project(R-type)
cmake_minimum_required(VERSION 2.8.12)
add_definitions("-fPIC")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

find_package(Qt5Widgets CONFIG REQUIRED)

include_directories(${CMAKE_INCLUDE_PATH})
add_executable(rtype_server main.cpp client.cpp player.cpp include/client.hpp include/player.hpp)
target_link_libraries(rtype_server ${CONAN_LIBS} Qt5::Widgets)
