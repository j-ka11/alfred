cmake_minimum_required(VERSION 3.22.0)

project(alfred)

add_executable(${PROJECT_NAME} Alfred.cpp Container.cpp ContainerStation.cpp Database.cpp Keyable.cpp PrimitiveContainer.cpp Valuable.cpp)