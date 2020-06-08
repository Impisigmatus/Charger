#include <gtest/gtest.h>

#include <Tests/Fixation.hpp>

TEST_F(CommandLineArgsF, Help)
{
  const int          ARGC   = 2;
  static const char* ARGV[] = {
    "ProgramName",
    "-h"
  };

  EXPECT_FALSE(obj->parse(ARGC, ARGV));
}

TEST_F(CommandLineArgsF, Args)
{
  const int          ARGC   = 3;
  static const char* ARGV[] = {
    "ProgramName",
    "-I/var",
    "--output=/usr"
  };

  EXPECT_TRUE(obj->parse(ARGC, ARGV));
  EXPECT_TRUE(obj->has("input") && obj->has("output"));

  EXPECT_EQ(obj->get<std::string>("input"),  "/var");
  EXPECT_EQ(obj->get<std::string>("output"), "/usr");
}

TEST_F(CommandLineArgsF, WithoutRequiredArgs)
{
  const int          ARGC   = 1;
  static const char* ARGV[] = {
    "ProgramName",
    "--output=/usr"
  };

  EXPECT_FALSE(obj->parse(ARGC, ARGV));
}

TEST_F(CommandLineArgsF, WithoutUnrequiredArgs)
{
  const int          ARGC   = 2;
  static const char* ARGV[] = {
    "ProgramName",
    "-I/var"
  };

  EXPECT_TRUE(obj->parse(ARGC, ARGV));
  EXPECT_FALSE(obj->has("output"));

  EXPECT_EQ(obj->get<std::string>("output"), std::string());
}
