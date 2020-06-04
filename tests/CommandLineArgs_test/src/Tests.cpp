#include <gtest/gtest.h>

#include <Tests/Fixation.hpp>

const int          ARGC   = 3;
static const char* ARGV[] = {
  "ProgrammName",
//  "--help",
  "-I /var",
  "--output-file=/usr"
};

TEST_F(CommandLineArgsF, Empty)
{
  obj->parse(ARGC, ARGV);
  obj->handle();
}
