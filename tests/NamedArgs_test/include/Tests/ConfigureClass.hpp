#ifndef TESTS_CONFIGURE_CLASS_HPP
#define TESTS_CONFIGURE_CLASS_HPP

#include <Tests/BaseClass.hpp>

#include <Charger/NamedArgs/Parser.hpp>
#include <Charger/NamedArgs/TagRegister.hpp>

namespace Tests {

enum Param
{
  AGE,
  NAME,
  LAST_NAME
};

namespace Arguments {
REGISTER_TAG(Param, AGE,       size_t);
REGISTER_TAG(Param, NAME,      std::string);
REGISTER_TAG(Param, LAST_NAME, std::string);
} // namespace Arguments

class ConfigureClass : public BaseClass
{
public:
  template<typename ...Args>
  void configure(const Args&... args)
  {
    set(Charger::NamedArgs::Parser<Param>::getOption<size_t>     (Param::AGE,       args...),
        Charger::NamedArgs::Parser<Param>::getOption<std::string>(Param::NAME,      args...),
        Charger::NamedArgs::Parser<Param>::getOption<std::string>(Param::LAST_NAME, args...));
  }

};

} // namespace Tests

#endif // TESTS_CONFIGURE_CLASS_HPP
