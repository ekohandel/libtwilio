find_program(CLANG_TIDY_EXECUTABLE NAMES clang-tidy)
mark_as_advanced(CLANG_TIDY_EXECUTABLE)

if (${CLANG_TIDY_EXECUTABLE} STREQUAL "CLANG_TIDY_EXECUTABLE-NOTFOUND")
  message(FATAL_ERROR "clang-tidy not found")
else()
  message(STATUS "Enabling clang-tidy")
  list(APPEND CMAKE_CXX_CLANG_TIDY
    "${CLANG_TIDY_EXECUTABLE}"
    "-checks=*,-modernize-use-trailing-return-type,-fuchsia-default-arguments-calls,-misc-non-private-member-variables-in-classes"
    "-warnings-as-errors=*"
    "-header-filter=include/twilio/*"
  )
endif()
