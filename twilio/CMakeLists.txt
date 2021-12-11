include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git GIT_TAG 1.7.2)
FetchContent_MakeAvailable(cpr)

set(CMAKE_CXX_STANDARD 11)

include("${PROJECT_SOURCE_DIR}/cmake/clang-tidy.cmake")

add_library(
  twilio SHARED 
  sms.cpp
)

target_include_directories(
  twilio PUBLIC
  ../include
)

target_link_libraries(twilio PRIVATE cpr::cpr)

install(
  TARGETS twilio
  LIBRARY
)
