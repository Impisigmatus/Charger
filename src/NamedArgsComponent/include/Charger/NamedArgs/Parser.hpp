#ifndef CHARGER_NAMEDARGS_PARSER_HPP
#define CHARGER_NAMEDARGS_PARSER_HPP

#include <utility>

namespace Charger {
namespace NamedArgs {

template<typename Tag>
class Parser
{
public:
  Parser() = default;

  template<typename T, typename T2, typename ...Args>
  static T getOption(const Tag& tag, const std::pair<Tag, T2>& arg, const Args&... args)
  {
    if (arg.first == tag)
      return handle<T>(arg.second);
    return getOption<T>(tag, args...);
  }

  template<typename T, typename T2>
  static T getOption(const Tag& tag, const std::pair<Tag, T2>& arg)
  {
    if (arg.first == tag)
      return handle<T>(arg.second);
    return T();
  }

  template<typename T, typename T2>
  static T handle(T2 value)
  {
    return *reinterpret_cast<T*>(&value);
  }

};

} // namespace NamedArgs
} // namespace Charger

#endif // CHARGER_NAMEDARGS_PARSER_HPP
