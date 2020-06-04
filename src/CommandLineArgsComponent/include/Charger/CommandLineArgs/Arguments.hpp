#ifndef CHARGER_COMMANDLINEARGS_STUB_HPP
#define CHARGER_COMMANDLINEARGS_STUB_HPP

#include <charger_commandlineargs_export.h>

#include <boost/program_options.hpp>

namespace Charger {
namespace CommandLineArgs {

class CHARGER_COMMANDLINEARGS_EXPORT Arguments
{
public:
  Arguments();

  void parse(int argc, const char** argv);

  void handle() const;

private:
  boost::program_options::variables_map       mMap;
  boost::program_options::options_description mDesc;

private: // HARDCODE
  std::string m_inputFilePath;
  std::string m_outputFilePath;

};

} // namespace CommandLineArgs
} // namespace Charger

#endif // CHARGER_COMMANDLINEARGS_STUB_HPP
