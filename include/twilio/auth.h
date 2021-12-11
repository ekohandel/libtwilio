#ifndef TWILIO_AUTH_H
#define TWILIO_AUTH_H

#include <string>

namespace twilio {
class Authentication {
 public:
  Authentication(std::string account_sid, std::string auth_token)
      : account_sid{std::move(account_sid)},
        auth_token{std::move(auth_token)} {}
  Authentication(std::string account_sid, std::string &&auth_token)
      : account_sid{std::move(account_sid)},
        auth_token{std::move(auth_token)} {}
  Authentication(std::string &&account_sid, std::string auth_token)
      : account_sid{std::move(account_sid)},
        auth_token{std::move(auth_token)} {}
  Authentication(std::string &&account_sid, std::string &&auth_token)
      : account_sid{std::move(account_sid)},
        auth_token{std::move(auth_token)} {}
  const std::string &AccountSID() const { return account_sid; }
  const std::string &AuthToken() const { return auth_token; }

 private:
  const std::string account_sid;
  const std::string auth_token;
};
}  // namespace twilio

#endif