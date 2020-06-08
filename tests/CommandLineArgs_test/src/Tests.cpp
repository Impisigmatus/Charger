#include <gtest/gtest.h>

#include <Tests/Fixation.hpp>

TEST_F(CommandLineArgsF, Help)
{
  const int          ARGC   = 2;
  static const char* ARGV[] = {
    "ProgrammName",
    "-h"
  };

  EXPECT_FALSE(obj->parse(ARGC, ARGV));
}

TEST_F(CommandLineArgsF, Args)
{
  const int          ARGC   = 3;
  static const char* ARGV[] = {
    "ProgrammName",
    "-I /var",
    "--output=/usr"
  };
  EXPECT_TRUE(obj->parse(ARGC, ARGV));
  obj->handle();
}
