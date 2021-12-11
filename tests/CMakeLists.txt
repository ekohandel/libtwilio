set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.11.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(
  sms_test
  sms_test.cpp
)
target_link_libraries(
  sms_test
  gtest_main
  twilio
)

include(GoogleTest)
gtest_discover_tests(sms_test)
