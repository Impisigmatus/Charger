#include <gtest/gtest.h>

#include <Tests/ChildClass.hpp>

TEST(NamedArgs, First)
{
  const std::string NAME      = "John";
  const std::string LAST_NAME = "Doe";
  const size_t      AGE       = 23;

  Tests::ChildClass obj;
  obj.configure(Arguments::NAME      = NAME,
                Arguments::AGE       = AGE,
                Arguments::LAST_NAME = LAST_NAME);
}
