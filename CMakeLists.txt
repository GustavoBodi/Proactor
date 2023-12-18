cmake_minimum_required(VERSION 3.22)
project(project
  VERSION 0.0.1)

set(CMAKE_CXX_FLAGS_INIT "-Wall -std=c++20")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
enable_testing()

find_path(uring_INCLUDE_DIR NAMES liburing.h)
find_library(uring_LIBRARIES
  NAMES liburing.a liburing)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(uring 
  DEFAULT_MSG uring_LIBRARIES uring_INCLUDE_DIR)

mark_as_advanced(
  uring_INCLUDE_DIR
  uring_LIBRARIES)

if(uring_FOUND AND NOT TARGET uring::uring)
  add_library(uring::uring UNKNOWN IMPORTED)
  set_target_properties(uring::uring PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${uring_INCLUDE_DIR}"
    IMPORTED_LINK_INTERFACE_LANGUAGES "C"
    IMPORTED_LOCATION "${uring_LIBRARIES}")
endif()

set(PROJECT_SOURCE_DIR "src")
set(PROJECT_SOURCE_LIB_MODULE "${PROJECT_SOURCE_DIR}/proactor")
set(PROJECT_INCLUDE_DIR "include")
set(PROJECT_SPHINX_DIR "docs_sphinx")
set(PROJECT_TEST_DIR "tests")

file (GLOB SRC_FILES
  "${PROJECT_SOURCE_LIB_MODULE}/*.cpp")

file (GLOB INCLUDE_FILES
  "${PROJECT_INCLUDE_DIR}/*.h*")

file (GLOB TEST_FILES
  "${PROJECT_TEST_DIR}/*.cpp")

include_directories(project "./include/" )
add_executable(project "${PROJECT_SOURCE_DIR}/main.cpp" ${SRC_FILES} ${INCLUDE_FILES} "${uring_INCLUDE_DIR}/liburing.h")
target_link_libraries(project -luring)

target_link_libraries(project PUBLIC )

find_package(Catch2 3 REQUIRED)
# These tests can use the Catch2-provided main
add_executable(tests "${PROJECT_TEST_DIR}/main.cpp" ${SRC_FILES} ${INCLUDE_FILES})
target_link_libraries(tests PRIVATE Catch2 Catch2::Catch2WithMain)

# These tests need their own main
add_executable(tests-main ${TEST_FILES} ${SRC_FILES})
target_link_libraries(tests-main PRIVATE Catch2::Catch2)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})

include(CTest)
include(Catch)
catch_discover_tests(tests)

