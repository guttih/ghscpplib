include(CTest)
enable_testing()

set(LIBDIR_DIR "${PROJECT_SOURCE_DIR}/ghscpplib")

include_directories("${LIBDIR_DIR}/include")
add_library(LibHello "${LIBDIR_DIR}/src/GhsCppLib/Hello.cpp")

target_sources("${PROJECT_NAME}" PRIVATE ${FILES}) 
add_executable(
  hello_test
  hello_test.cc
)



target_link_libraries(
  hello_test
  GTest::gtest_main
  LibHello
)

include(GoogleTest)
gtest_discover_tests(hello_test)

message("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ")
message("- - - - - -                 Configuring helloTest                 - - - - - - ")
message("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ")