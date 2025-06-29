cmake_minimum_required(VERSION 3.15)
project(gravitySim C)

find_package(raylib REQUIRED)

add_executable(gravitySim)

target_include_directories(gravitySim PRIVATE include)

add_subdirectory(src)

target_link_libraries(gravitySim PRIVATE m raylib)
