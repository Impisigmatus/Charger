#include <Arguments.hpp>

#include <iostream>

namespace Charger {
namespace CommandLineArgs {

Arguments::Arguments()
{
  std::cerr << "Constructor\n";
}

Arguments::~Arguments()
{
  std::cerr << "Destructor\n";
}

} // namespace CommandLineArgs
} // namespace Charger
