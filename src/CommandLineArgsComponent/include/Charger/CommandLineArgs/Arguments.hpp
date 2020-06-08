#ifndef CHARGER_COMMANDLINEARGS_ARGUMENTS_HPP
#define CHARGER_COMMANDLINEARGS_ARGUMENTS_HPP

#include <charger_commandlineargs_export.h>

#include <boost/program_options.hpp>

namespace Charger {
namespace CommandLineArgs {

class CHARGER_COMMANDLINEARGS_EXPORT Arguments
{
public:
  Arguments();

  template<typename T>
  void addOption(const std::string& name,
                 const std::string& description)
  {
    auto semantic = boost::program_options::value<T>();
    mOptions.add_options()(name.c_str(), semantic, description.c_str());
  }

  bool parse(int argc, const char** argv);

  void handle() const;

private:
  boost::program_options::options_description mOptions;
  boost::program_options::variables_map       mData;

};

} // namespace CommandLineArgs
} // namespace Charger

#endif // CHARGER_COMMANDLINEARGS_ARGUMENTS_HPP
