#ifndef TWILIO_TESTS_MAGIC_H
#define TWILIO_TESTS_MAGIC_H

#include <string>

namespace twilio {
namespace magic {
namespace sms {
namespace from {
static const std::string INVALID_NUMBER = "+15005550001";
static const std::string NOT_OWNED_NUMBER = "+15005550007";
static const std::string QUEUE_FULL_NUMBER = "+15005550008";
static const std::string VALID_NUMBER = "+15005550006";
}  // namespace from
namespace to {
static const std::string VALID_NUMBER = "+15005550000";
static const std::string INVALID_NUMBER = "+15005550001";
static const std::string CANNOT_ROUTE_NUMBER = "+15005550002";
static const std::string NO_INTERNATION_PERMISSION_NUMBER = "+15005550003";
static const std::string BLOCKED_NUMBER = "+15005550004";
static const std::string NO_SMS_NUMBER = "+15005550009";
}  // namespace to
}  // namespace sms
}  // namespace magic
}  // namespace twilio

#endif