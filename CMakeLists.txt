cmake_minimum_required(VERSION 3.22.0)

project(alfred CXX)

add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_11)

add_subdirectory(src)