#include <Tests/BaseClass.hpp>

namespace Tests {

void BaseClass::set(const size_t age, const std::string& name, const std::string& lastName)
{
  mAge      = age;
  mName     = name;
  mLastName = lastName;
}

} // namespace Tests
