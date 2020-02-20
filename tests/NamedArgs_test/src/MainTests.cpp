#include <gtest/gtest.h>

#include <Tests/ChildClass.hpp>

TEST(NamedArgs, FullConfigure)
{
  const size_t      AGE       = 23;
  const std::string NAME      = "John";
  const std::string LAST_NAME = "Doe";

  Tests::ChildClass obj;
  obj.configure(Arguments::AGE       = AGE,
                Arguments::NAME      = NAME,
                Arguments::LAST_NAME = LAST_NAME);

  EXPECT_EQ(AGE,       obj.getAge());
  EXPECT_EQ(NAME,      obj.getName());
  EXPECT_EQ(LAST_NAME, obj.getLastName());
}

TEST(NamedArgs, OneArgumentConfigure)
{
  const std::string NAME = "John";

  Tests::ChildClass obj;
  obj.configure(Arguments::NAME = NAME);

  EXPECT_EQ(size_t(),      obj.getAge());
  EXPECT_EQ(NAME,          obj.getName());
  EXPECT_EQ(std::string(), obj.getLastName());
}

TEST(NamedArgs, ReverseConfigure)
{
  const size_t      AGE       = 23;
  const std::string NAME      = "John";
  const std::string LAST_NAME = "Doe";

  Tests::ChildClass obj;
  obj.configure(Arguments::LAST_NAME = LAST_NAME,
                Arguments::AGE       = AGE,
                Arguments::NAME      = NAME);

  EXPECT_EQ(AGE,       obj.getAge());
  EXPECT_EQ(NAME,      obj.getName());
  EXPECT_EQ(LAST_NAME, obj.getLastName());
}

TEST(NamedArgs, AmbiguousConfigure)
{
  const size_t      AGE = 23;

  Tests::ChildClass obj;
  obj.configure(Arguments::AGE = AGE,
                Arguments::AGE = 24);

  EXPECT_EQ(AGE,           obj.getAge());
  EXPECT_EQ(std::string(), obj.getName());
  EXPECT_EQ(std::string(), obj.getLastName());
}
