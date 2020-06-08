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

  template<typename T>
  T get(const std::string& name) const
  {
    return mData[name].as<T>();
  }

  bool parse(int argc, const char** argv);

  bool has(const std::string& name) const;

private:
  boost::program_options::options_description mOptions;
  boost::program_options::variables_map       mData;

};

} // namespace CommandLineArgs
} // namespace Charger

#endif // CHARGER_COMMANDLINEARGS_ARGUMENTS_HPP
