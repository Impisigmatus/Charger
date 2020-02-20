#ifndef CHARGER_NAMEDARGS_TAGREGISTER_HPP
#define CHARGER_NAMEDARGS_TAGREGISTER_HPP

#include <charger_namedargs_export.h>

#define \
  REGISTER_TAG(NAME, TYPE) \
  struct CHARGER_NAMEDARGS_EXPORT NAME##_tag \
  { \
    std::pair<TAG_MACRO, TYPE> operator=(const TYPE& value) const \
    { \
      return std::make_pair(TAG_MACRO::NAME, value); \
    } \
    NAME##_tag(int) {} \
  }; \
  const NAME##_tag NAME = 0

#endif // CHARGER_NAMEDARGS_TAGREGISTER_HPP
