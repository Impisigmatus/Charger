#include <Arguments.hpp>

#include <iostream>

namespace Charger {
namespace CommandLineArgs {

Arguments::Arguments()
  : mOptions("Usage")
{
  mOptions.add_options()("help,h", "For more information");
}

bool Arguments::parse(int argc, const char** argv)
{
  auto data = boost::program_options::parse_command_line(argc, argv, mOptions);
  boost::program_options::store(data, mData);
  boost::program_options::notify(mData);

  if (mData.count("help"))
  {
    std::cout << mOptions << std::endl;
    return false;
  }
  return true;
}

bool Arguments::has(const std::string& name) const
{
  return mData.count(name.c_str());
}

} // namespace CommandLineArgs
} // namespace Charger
