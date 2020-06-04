#include <Arguments.hpp>

#include <iostream>

namespace Charger {
namespace CommandLineArgs {

void Arguments::parse(int argc, const char** argv)
{
  for (int i=0; i < argc; i++)
    std::cout << i << ") " << argv[i] << std::endl;
}

} // namespace CommandLineArgs
} // namespace Charger
