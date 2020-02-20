#include <gtest/gtest.h>

#include <Tests/ChildClass.hpp>

TEST(NamedArgs, FullConfigure)
{
  const std::string NAME      = "John";
  const std::string LAST_NAME = "Doe";
  const size_t      AGE       = 23;

  Tests::ChildClass obj;
  obj.configure(Arguments::NAME      = NAME,
                Arguments::AGE       = AGE,
                Arguments::LAST_NAME = LAST_NAME);

  EXPECT_EQ(AGE,       obj.getAge());
  EXPECT_EQ(NAME,      obj.getName());
  EXPECT_EQ(LAST_NAME, obj.getLastName());
}
