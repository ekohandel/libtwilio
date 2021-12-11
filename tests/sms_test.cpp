#include "twilio/sms.h"

#include <gtest/gtest.h>

#include "twilio/magic.h"

class SMSTestFixture : public ::testing::Test {
 protected:
  std::string account_sid;
  std::string auth_token;

  void SetUp() override {
    account_sid = std::getenv("ACCOUNT_SID");
    auth_token = std::getenv("AUTH_TOKEN");
  }

  void TearDown() override {}
};

class SMSBadToNumbersTestFixture
    : public SMSTestFixture,
      public ::testing::WithParamInterface<std::string> {};
TEST_P(SMSBadToNumbersTestFixture, BadToNumbers) {
  auto sms = twilio::SMS(twilio::Authentication(account_sid, auth_token));

  auto msg =
      twilio::messages::Message()
          .With(twilio::messages::From{twilio::magic::sms::from::VALID_NUMBER})
          .With(twilio::messages::To{GetParam()})
          .With(twilio::messages::Body{"Hello World!"});
  EXPECT_THROW(sms.Send(msg), twilio::SMSSendException);
}
INSTANTIATE_TEST_SUITE_P(
    BadToNumbers, SMSBadToNumbersTestFixture,
    testing::Values(twilio::magic::sms::to::INVALID_NUMBER,
                    twilio::magic::sms::to::CANNOT_ROUTE_NUMBER,
                    twilio::magic::sms::to::NO_INTERNATION_PERMISSION_NUMBER,
                    twilio::magic::sms::to::BLOCKED_NUMBER,
                    twilio::magic::sms::to::NO_SMS_NUMBER));

class SMSBadFromNumbersTestFixture
    : public SMSTestFixture,
      public ::testing::WithParamInterface<std::string> {};
TEST_P(SMSBadFromNumbersTestFixture, BadFromNumbers) {
  auto sms = twilio::SMS(twilio::Authentication(account_sid, auth_token));

  auto msg =
      twilio::messages::Message()
          .With(twilio::messages::From{GetParam()})
          .With(twilio::messages::To{twilio::magic::sms::to::VALID_NUMBER})
          .With(twilio::messages::Body{"Hello World!"});
  EXPECT_THROW(sms.Send(msg), twilio::SMSSendException);
}
INSTANTIATE_TEST_SUITE_P(
    BadFromNumbers, SMSBadFromNumbersTestFixture,
    testing::Values(twilio::magic::sms::from::INVALID_NUMBER,
                    twilio::magic::sms::from::NOT_OWNED_NUMBER,
                    twilio::magic::sms::from::QUEUE_FULL_NUMBER));

TEST_F(SMSTestFixture, HelloWorld) {
  auto sms = twilio::SMS(twilio::Authentication(account_sid, auth_token));

  auto msg =
      twilio::messages::Message()
          .With(twilio::messages::From{twilio::magic::sms::from::VALID_NUMBER})
          .With(twilio::messages::To{twilio::magic::sms::to::VALID_NUMBER})
          .With(twilio::messages::Body{"Hello World!"});
  EXPECT_NO_THROW(sms.Send(msg));
}

TEST_F(SMSTestFixture, BadMessage) {
  auto sms = twilio::SMS(twilio::Authentication(account_sid, auth_token));

  auto msg = twilio::messages::Message();
  EXPECT_THROW(sms.Send(msg), twilio::SMSSendException);
}