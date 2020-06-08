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

  EXPECT_TRUE(false) << "Please, use --help for more information";
}
