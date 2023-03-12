enable_testing()


set(LIBDIR_DIR "${PROJECT_SOURCE_DIR}/ghscpplib")

include_directories("${LIBDIR_DIR}/include")
add_library(LibVersion "${LIBDIR_DIR}/src/GhsCppLib/Version.cpp")

target_sources("${PROJECT_NAME}" PRIVATE ${FILES}) 
add_executable(
  hello_test
  hello_test.cc
)



target_link_libraries(
  hello_test
  GTest::gtest_main
  LibVersion
)

include(GoogleTest)
gtest_discover_tests(hello_test)

message("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ")
message("PROJECT_SOURCE_DIR      : " ${PROJECT_SOURCE_DIR})
message("CMAKE_CURRENT_SOURCE_DIR: " ${CMAKE_CURRENT_SOURCE_DIR})
MESSAGE("RELATIVE_DIR            : " ${RELATIVE_DIR})
message("Need these dirs:")

message("Source  directory       : ${LIBDIR_DIR}/src/GhsCppLib")
message("Include directory       : ${LIBDIR_DIR}/include/GhsCppLib")
message("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ")