#ifndef TWILIO_MESSAGE_H
#define TWILIO_MESSAGE_H

#include <memory>
#include <string>
#include <vector>

namespace twilio {
namespace messages {

class Param {
 public:
  Param(std::string name, std::string&& value)
      : name{std::move(name)}, value{value} {}
  std::string Name() const { return name; }
  std::string Value() const { return value; }

 private:
  const std::string name;
  const std::string value;
};

class To : public Param {
 public:
  explicit To(std::string to) : Param("To", std::move(to)) {}
};

class From : public Param {
 public:
  explicit From(std::string from) : Param("From", std::move(from)) {}
};

class Body : public Param {
 public:
  explicit Body(std::string body) : Param("Body", std::move(body)) {}
};

class Attempt : public Param {
 public:
  explicit Attempt(int attempt) : Param("Attempt", std::to_string(attempt)) {}
};

class MaxPrice : public Param {
 public:
  explicit MaxPrice(float price) : Param("MaxPrice", std::to_string(price)) {}
};

class Message {
 public:
  template <typename T>
  Message& With(T&& param) {
    params.push_back(std::make_shared<T>(param.Value()));
    return *this;
  }
  const std::vector<std::shared_ptr<Param>>& Params() const { return params; }

 private:
  std::vector<std::shared_ptr<Param>> params{};
};

}  // namespace messages
}  // namespace twilio
#endif