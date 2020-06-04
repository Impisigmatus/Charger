#include <Tests/Fixation.hpp>

void CommandLineArgsF::SetUp()
{
  obj.reset(new Charger::CommandLineArgs::Arguments());
}

void CommandLineArgsF::TearDown()
{
  obj.reset();
}
