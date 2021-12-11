#include "twilio/sms.h"

#include <cpr/cpr.h>

#include <iostream>

namespace twilio {
SMS::SMS(Authentication authentication)
    : authentication{std::move(authentication)} {}

void SMS::Send(const messages::Message &message) {
  auto body = cpr::Multipart{};

  for (const auto &param : message.Params()) {
    body.parts.emplace_back(param->Name(), param->Value());
  }

  auto response =
      cpr::Post(cpr::Url{"https://api.twilio.com/2010-04-01/Accounts/",
                         authentication.AccountSID(), "/Messages.json"},
                cpr::Authentication{authentication.AccountSID(),
                                    authentication.AuthToken()},
                body);

  if (response.status_code != cpr::status::HTTP_CREATED) {
    throw SMSSendException(response.text);
  }
}

void SMS::Send(const messages::Message &&message) { Send(message); }

SMSSendException::SMSSendException(std::string message)
    : message{std::move(message)} {}

SMSSendException::SMSSendException(std::string &&message)
    : message{std::move(message)} {}

const char *SMSSendException::what() const noexcept { return message.c_str(); }
}  // namespace twilio