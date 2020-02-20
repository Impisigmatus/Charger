#include <gtest/gtest.h>

enum class Param;
#define TAG_MACRO Param
#include <Charger/NamedArgs/Parser.hpp>

enum class Param
{
  AGE,
  NAME,
  LAST_NAME
};

namespace Arguments {
REGISTER_TAG(AGE,       int);
REGISTER_TAG(NAME,      std::string);
REGISTER_TAG(LAST_NAME, std::string);
} // namespace Arguments
#undef TAG_MACRO

TEST(NamedArgs, First)
{}
