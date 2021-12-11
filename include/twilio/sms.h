#ifndef TWILIO_SMS_H
#define TWILIO_SMS_H

#include "auth.h"
#include "message.h"

namespace twilio {
class SMS {
 public:
  explicit SMS(Authentication authentication);
  void Send(const messages::Message &message);
  void Send(const messages::Message &&message);

 private:
  const Authentication authentication;
};

class SMSSendException : std::exception {
 public:
  explicit SMSSendException(std::string message);
  explicit SMSSendException(std::string &&message);
  const char *what() const noexcept override;

 private:
  const std::string message;
};
}  // namespace twilio

#endif