#include <Tests/BaseClass.hpp>

namespace Tests {

void BaseClass::set(const size_t age, const std::string& name, const std::string& lastName)
{
  mAge      = age;
  mName     = name;
  mLastName = lastName;
}

size_t BaseClass::getAge() const
{
  return mAge;
}

std::string BaseClass::getName() const
{
  return mName;
}

std::string BaseClass::getLastName() const
{
  return mLastName;
}

} // namespace Tests
