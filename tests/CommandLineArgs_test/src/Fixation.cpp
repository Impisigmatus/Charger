#include <Tests/Fixation.hpp>

void CommandLineArgsF::SetUp()
{
  obj.reset(new Charger::CommandLineArgs::Stub());
}

void CommandLineArgsF::TearDown()
{
  obj.reset();
}
