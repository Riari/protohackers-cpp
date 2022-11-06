cmake_minimum_required(VERSION 3.7)

project(Protohackers)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Threads)

include(FetchContent)
include(./cmake/fetch_boost.cmake)
include(./cmake/fetch_asio.cmake)

file(GLOB_RECURSE SOURCES "src/*.cpp")

set(SOURCES ${SOURCES})

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE
  ${CMAKE_THREAD_LIBS_INIT}
  boost_bind
  asio)
