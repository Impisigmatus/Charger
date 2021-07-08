#ifndef CHARGER_HTTP_CLIENT_CURL_SPEAKER_HPP
#define CHARGER_HTTP_CLIENT_CURL_SPEAKER_HPP

#include <Charger/Http/Client/ISpeaker.hpp>

#include <memory>

#include <curl/curl.h>

namespace Charger::Http::Client::curl {

/*!
 * \brief Класс реализации HTTP клиента средствами libcurl
 */
class Speaker : public ISpeaker
{
public:
  /*!
   * \brief Конструктор по-умолчанию
   * \details Инициализирует объект cURL, настраивает базовые опции для всех запросов
   */
  Speaker();

  /*!
   * \brief Конфигурирует cURL опции и выполняет запрос
   * \param request Запрос
   * \param method Метод запроса
   * \return Charger::Http::Response Ответ
   */
  Response custom(const Request& request, const::std::string& method) const override;

protected:
  /*!
   * \brief Выполняет сконфигурированный HTTP запрос
   * \return Charger::Http::Response Ответ
   */
  Response exec() const;

  /*!
   * \brief Разбирает ответ сервера на Charger::Http::Response
   * \param data Метаинформация ответа
   * \param body Тело ответа
   * \return Charger::Http::Response Объект ответа
   */
  Response parse(const std::string& data, std::string body) const;

  /*!
   * \brief Преобразует строку в безопасную для передачи в GET параметры
   * \param str Исходная строка
   * \return std::string Безопасная строка
   */
  std::string escape(const std::string& str) const;

  /*!
   * \brief Callback функция для чтения данных из cURL запросов
   * \param data Исходные данные
   * \param size Размер передаваемых блоков памяти
   * \param nmemb Кол-во передаваемых блоков памяти
   * \param buffer Указатель на буфер в который читаем
   * \return Размер прочитанного буфера
   */
  static size_t callback(char* data, size_t size, size_t nmemb, std::string* buffer);

protected:
  std::unique_ptr<CURL, decltype(&curl_easy_cleanup)> mCurl; //!< Объект cURL

};

} // namespace Charger::Http::Client::curl

#endif // CHARGER_HTTP_CLIENT_CURL_SPEAKER_HPP
