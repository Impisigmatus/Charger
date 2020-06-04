#ifndef TESTS_COMMANDLINEARGS_FIXATION_HPP
#define TESTS_COMMANDLINEARGS_FIXATION_HPP

#include <Charger/CommandLineArgs/Stub.hpp>

#include <gtest/gtest.h>

#include <memory>

class CommandLineArgsF : public ::testing::Test
{
public:
  void SetUp() final override;

  void TearDown() final override;

public:
  std::shared_ptr<Charger::CommandLineArgs::Stub> obj;

};


#endif // TESTS_COMMANDLINEARGS_FIXATION_HPP
