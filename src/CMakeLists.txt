add_executable(alfred Alfred.cpp Blob.cpp Container.cpp ContainerStation.cpp Database.cpp Keyable.cpp PrimitiveContainer.cpp Valuable.cpp)
target_include_directories(alfred PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(alfred PRIVATE project_options)