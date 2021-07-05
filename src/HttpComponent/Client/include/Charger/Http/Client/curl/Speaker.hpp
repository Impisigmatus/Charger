#ifndef CHARGER_HTTP_CLIENT_CURL_SPEAKER_HPP
#define CHARGER_HTTP_CLIENT_CURL_SPEAKER_HPP

#include <Charger/Http/Client/ISpeaker.hpp>

#include <memory>

#include <curl/curl.h>

namespace Charger::Http::Client::curl {

class Speaker : ISpeaker
{
public:
  Speaker();

  Response custom(const Request& request, const::std::string& method) const override;

protected:
  Response exec() const;

  Response parse(const std::string& data, std::string body) const;

  std::string escape(const std::string& str) const;

  static size_t callback(char* data, size_t size, size_t nmemb, std::string* buffer);

protected:
  std::unique_ptr<CURL, decltype(&curl_easy_cleanup)> mCurl;

};

} // namespace Charger::Http::Client::curl

#endif // CHARGER_HTTP_CLIENT_CURL_SPEAKER_HPP
