#include <curl/Speaker.hpp>

#include <sstream>

namespace Charger::Http::Client::curl {

Speaker::Speaker()
  : mCurl(curl_easy_init(), &curl_easy_cleanup)
{
  curl_easy_setopt(mCurl.get(), CURLOPT_FOLLOWLOCATION, 1);
  curl_easy_setopt(mCurl.get(), CURLOPT_WRITEFUNCTION, &Speaker::callback);
}

Response Speaker::custom(const Request& request, const std::string& method) const
{
  std::string uri = request.getURL();
  if (!request.getArgs().empty())
  {
    uri += (uri.find('?') == std::string::npos ? "?" : "&");
    for (const auto& arg : request.getArgs())
      uri += arg.first + "=" + escape(arg.second) + "&";
    uri.pop_back();
  }

  curl_easy_setopt(mCurl.get(), CURLOPT_URL, uri.c_str());
  curl_easy_setopt(mCurl.get(), CURLOPT_CUSTOMREQUEST, method.c_str());
  curl_easy_setopt(mCurl.get(), CURLOPT_POSTFIELDS, request.getData().c_str());

  curl_slist* headers = nullptr;
  for (const auto& header : request.getHeaders())
    headers = curl_slist_append(headers, std::string(header.first + ": " + header.second).c_str());
  curl_easy_setopt(mCurl.get(), CURLOPT_HTTPHEADER, headers);

  auto response = exec();
  curl_slist_free_all(headers);
  return response;
}

Response Speaker::exec() const
{
  if (!mCurl)
    return { 400, "Bad Request", "Invalid cURL" };

  std::string body;
  std::string data;
  curl_easy_setopt(mCurl.get(), CURLOPT_WRITEDATA,  &body);
  curl_easy_setopt(mCurl.get(), CURLOPT_HEADERDATA, &data);

  auto code = curl_easy_perform(mCurl.get());
  if (code)
    return { 400, "Bad Request", curl_easy_strerror(code) };

  return parse(data, body);
}

Response Speaker::parse(const std::string& data, std::string body) const
{
  std::map<std::string, std::string> headers; // TODO не возвращаются
  if (body.back() == '\n')
    body.pop_back();

  std::istringstream stream(data);
  std::string line;
  while (std::getline(stream, line))
  {
    line = line.substr(0, line.rfind('\r'));
    if (line.empty())
      continue;

    if (line.find(':') == std::string::npos)
    {
      line = line.substr(line.find(' ') + 1); // Отрезаем версию http
      size_t separator = line.find(' '); // Находим разделитель между кодом и пояснением
      return { std::stoul(line.substr(0, separator)), line.substr(separator + 1), body };
    }

    size_t separator = line.find(':');
    headers.insert({
      line.substr(0, separator),
      line.substr(separator + 2) // 2 символа это ": "
    });
  }
  return { 400, "Bad Request", "Invalid response" };
}

std::string Speaker::escape(const std::string& str) const
{
  std::unique_ptr<char, decltype(&curl_free)> esc_text(curl_easy_escape(mCurl.get(), str.c_str(), str.length()), &curl_free);
  if(!esc_text)
    return std::string();
  return esc_text.get();
}

size_t Speaker::callback(char* data, size_t size, size_t nmemb, std::string* buffer)
{
  if (!buffer || !data)
    return 0;

  size_t result = size * nmemb;
  buffer->append(data, result);
  return result;
}

} // namespace Charger::Http::Client::curl
