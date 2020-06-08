#include <Tests/Fixation.hpp>

void CommandLineArgsF::SetUp()
{
  obj.reset(new Charger::CommandLineArgs::Arguments());
  obj->addOption<std::string>("input,I", "Input path(example: /path/to)", true);
  obj->addOption<std::string>("output",  "Output path(example: /path/to)");
}

void CommandLineArgsF::TearDown()
{
  obj.reset();
}
