cmake_minimum_required(VERSION 3.20)

project (HTTP_MCX VERSION 0.1 DESCRIPTION "proto MCX")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Debug was set by default" FORCE)
endif()

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

include(CMakeDependentOption)
option(WITH_TESTS "Build with tests" OFF)
cmake_dependent_option(WITH_COVERAGE "Build with code coverage" ON "WITH_TESTS" ON)

if (WITH_COVERAGE)
  include(CodeCoverage)
  append_coverage_compiler_flags()
endif()

find_package(Poco REQUIRED COMPONENTS Foundation Net Util)

set(HDR_FILES
    include/handlers.hpp
    include/mother_handler.hpp
)

set(SRC_FILES
    src/handlers.cpp
    src/mother_handler.cpp
)

set(SRC_MAIN_FILES
    src/main.cpp
)

add_library(${PROJECT_NAME}_lib ${SRC_FILES} ${HDR_FILES})
target_include_directories(${PROJECT_NAME}_lib PUBLIC include)

add_executable(${PROJECT_NAME} ${SRC_MAIN_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_lib)
target_link_libraries(${PROJECT_NAME} PRIVATE Poco::Foundation Poco::Util Poco::Net)

if (WITH_TESTS)
  find_package(GTest REQUIRED)
  enable_testing()
  add_subdirectory(tests)

  if (WITH_COVERAGE)
    set(GCOVR_ADDITIONAL_ARGS --print-summary)
    setup_target_for_coverage_gcovr_xml(
        NAME "coverage-gcov"
        EXECUTABLE ctest
        BASE_DIRECTORY "${CMAKE_SOURCE_DIR}"
        EXCLUDE ${CMAKE_SOURCE_DIR}/${SRC_MAIN_FILES})

    setup_target_for_coverage_lcov(
          NAME "coverage-lcov"
          EXECUTABLE ctest
          BASE_DIRECTORY "${CMAKE_SOURCE_DIR}"
          EXCLUDE ${CMAKE_SOURCE_DIR}/${SRC_MAIN_FILES} "/usr/*")
  endif()
endif()