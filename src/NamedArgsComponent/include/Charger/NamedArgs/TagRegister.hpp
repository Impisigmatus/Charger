#ifndef CHARGER_NAMEDARGS_TAGREGISTER_HPP
#define CHARGER_NAMEDARGS_TAGREGISTER_HPP

#define \
  REGISTER_TAG(TAG, NAME, TYPE) \
  struct NAME##_tag \
  { \
    std::pair<TAG, TYPE> operator=(const TYPE& value) const \
    { \
      return std::make_pair(TAG::NAME, value); \
    } \
    NAME##_tag(int) {} \
  }; \
  const NAME##_tag NAME = 0

#endif // CHARGER_NAMEDARGS_TAGREGISTER_HPP
