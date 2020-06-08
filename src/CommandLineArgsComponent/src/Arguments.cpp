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

void Arguments::handle() const
{
  if (mData.count("input") && mData.count("output"))
    std::cerr << "Input: "  << mData["input"].as<std::string>()  << std::endl
              << "Output: " << mData["output"].as<std::string>() << std::endl;
  else
    std::cerr << "Please, use --help for more information" << std::endl;\
}

} // namespace CommandLineArgs
} // namespace Charger
