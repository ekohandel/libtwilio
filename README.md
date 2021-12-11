![CI](https://github.com/ekohandel/libtwilio/actions/workflows/ci.yml/badge.svg)

# libtwilio

Simple to use Twilio library in C++.

## Description

Work in progress project that intends to be a complete Twilio library.

## Getting Started

### Dependencies

* [libcpr](https://github.com/libcpr/cpr)

### Installing

* TBD

### Usage Example

Simple SMS Send:

```c++
#include <twilio/sms.h>

int main(int argc, char* argv[]) {
  twilio::SMS(twilio::Authentication("ACCOUNT_SID", "AUTH_TOKEN"))
    .Send(twilio::messages::Message()
      .With(twilio::messages::From{"+15005550006"})
      .With(twilio::messages::To{"+15005550006"})
      .With(twilio::messages::Body{"Hello World!"}));
}
```

## Version History

* None
    * Initial Release

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgments