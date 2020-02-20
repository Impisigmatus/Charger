#include <gtest/gtest.h>

#include <Tests/ConfigureClass.hpp>

TEST(NamedArgs, FullConfigure)
{
  const size_t      AGE       = 23;
  const std::string NAME      = "John";
  const std::string LAST_NAME = "Doe";

  Tests::ConfigureClass obj;
  obj.configure(Tests::Arguments::AGE       = AGE,
                Tests::Arguments::NAME      = NAME,
                Tests::Arguments::LAST_NAME = LAST_NAME);

  EXPECT_EQ(AGE,       obj.getAge());
  EXPECT_EQ(NAME,      obj.getName());
  EXPECT_EQ(LAST_NAME, obj.getLastName());
}

TEST(NamedArgs, OneArgumentConfigure)
{
  const std::string NAME = "John";

  Tests::ConfigureClass obj;
  obj.configure(Tests::Arguments::NAME = NAME);

  EXPECT_EQ(size_t(),      obj.getAge());
  EXPECT_EQ(NAME,          obj.getName());
  EXPECT_EQ(std::string(), obj.getLastName());
}

TEST(NamedArgs, ReverseConfigure)
{
  const size_t      AGE       = 23;
  const std::string NAME      = "John";
  const std::string LAST_NAME = "Doe";

  Tests::ConfigureClass obj;
  obj.configure(Tests::Arguments::LAST_NAME = LAST_NAME,
                Tests::Arguments::AGE       = AGE,
                Tests::Arguments::NAME      = NAME);

  EXPECT_EQ(AGE,       obj.getAge());
  EXPECT_EQ(NAME,      obj.getName());
  EXPECT_EQ(LAST_NAME, obj.getLastName());
}

TEST(NamedArgs, AmbiguousConfigure)
{
  const size_t AGE = 23;

  Tests::ConfigureClass obj;
  obj.configure(Tests::Arguments::AGE = AGE,
                Tests::Arguments::AGE = 24);

  EXPECT_EQ(AGE,           obj.getAge());
  EXPECT_EQ(std::string(), obj.getName());
  EXPECT_EQ(std::string(), obj.getLastName());
}
