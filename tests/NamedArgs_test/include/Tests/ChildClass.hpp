#ifndef TESTS_CHILD_CLASS_HPP
#define TESTS_CHILD_CLASS_HPP

#include <Tests/BaseClass.hpp>

enum class Param;
#define TAG_MACRO Param
#include <Charger/NamedArgs/Parser.hpp>

enum class Param
{
  AGE,
  NAME,
  LAST_NAME
};

namespace Arguments {
REGISTER_TAG(AGE,       size_t);
REGISTER_TAG(NAME,      std::string);
REGISTER_TAG(LAST_NAME, std::string);
} // namespace Arguments
#undef TAG_MACRO

namespace Tests {

class ChildClass : public BaseClass
{
public:
  template<typename ...Args>
  void configure(const Args&... args)
  {
    set(Charger::NamedArgs::Parser::getOption<size_t>     (Param::AGE,       args...),
        Charger::NamedArgs::Parser::getOption<std::string>(Param::NAME,      args...),
        Charger::NamedArgs::Parser::getOption<std::string>(Param::LAST_NAME, args...));
  }

};

} // namespace Tests

#endif // TESTS_CHILD_CLASS_HPP
