#ifndef CHARGER_COMMANDLINEARGS_STUB_HPP
#define CHARGER_COMMANDLINEARGS_STUB_HPP

#include <charger_commandlineargs_export.h>

namespace Charger {
namespace CommandLineArgs {

class CHARGER_COMMANDLINEARGS_EXPORT Arguments
{
public:
  Arguments() = default;

  void parse(int argc, const char** argv);

};

} // namespace CommandLineArgs
} // namespace Charger

#endif // CHARGER_COMMANDLINEARGS_STUB_HPP
