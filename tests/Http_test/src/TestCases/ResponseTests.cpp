#include <gtest/gtest.h>

#include <Charger/Http/Response.hpp>

TEST(Response, WithoutBody)
{
  const size_t      CODE   = 200;
  const std::string REASON = "OK";

  Charger::Http::Response response(CODE, REASON);

  EXPECT_EQ(response.getCode(),   CODE);
  EXPECT_EQ(response.getReason(), REASON);
  EXPECT_EQ(response.getBody(),   REASON);
}

TEST(Response, WithBody)
{
  const size_t      CODE   = 200;
  const std::string REASON = "OK";
  const std::string BODY   = "All is OK!";

  Charger::Http::Response response(CODE, REASON, BODY);

  EXPECT_EQ(response.getCode(),   CODE);
  EXPECT_EQ(response.getReason(), REASON);
  EXPECT_EQ(response.getBody(),   BODY);
}
