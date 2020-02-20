#ifndef CHARGER_NAMEDARGS_PARSER_HPP
#define CHARGER_NAMEDARGS_PARSER_HPP

#include <charger_namedargs_export.h>

#include <Charger/NamedArgs/TagRegister.hpp>

#include <string>

namespace Charger {
namespace NamedArgs {

class CHARGER_NAMEDARGS_EXPORT Parser
{
public:
  Parser() = default;

  template<typename T, typename T2, typename ...Args>
  static T getOption(const TAG_MACRO& tag, const std::pair<TAG_MACRO, T2>& arg, const Args&... args)
  {
    if (arg.first == tag)
      return handle<T>(arg.second);
    return getOption<T>(tag, args...);
  }

  template<typename T, typename T2>
  static T getOption(const TAG_MACRO& tag, const std::pair<TAG_MACRO, T2>& arg)
  {
    if (arg.first == tag)
      return handle<T>(arg.second);
    return T();
  }

  template<typename T, typename T2>
  static T handle(T2 value)
  {
    return *reinterpret_cast<T>(&value);
  }

};

} // namespace NamedArgs
} // namespace Charger

#endif // CHARGER_NAMEDARGS_PARSER_HPP