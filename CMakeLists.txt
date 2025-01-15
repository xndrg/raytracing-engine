cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME "Raytracer")
set(CMAKE_CXX_STANDARD 14)
project(${PROJECT_NAME})

set(SOURCE_FILES
  src/main.cpp
  src/vec.cpp
  src/color.cpp
  src/ray.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE include/)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -ggdb)
