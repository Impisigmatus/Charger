#ifndef TESTS_BASE_CLASS_HPP
#define TESTS_BASE_CLASS_HPP

#include <string>

namespace Tests {

class BaseClass
{
public:
  BaseClass() = default;

  void set(const size_t age, const std::string& name, const std::string& lastName);

private:
  size_t      mAge;
  std::string mName;
  std::string mLastName;

};

} // namespace Tests

#endif // TESTS_BASE_CLASS_HPP
