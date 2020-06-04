#include <gtest/gtest.h>

#include <Tests/Fixation.hpp>

const int          ARGC   = 3;
static const char* ARGV[] = {
  "arg1",
  "arg2",
  "arg3"
};

TEST_F(CommandLineArgsF, Empty)
{
  obj->parse(ARGC, ARGV);
}
