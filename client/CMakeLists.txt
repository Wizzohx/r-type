project(R-type)
cmake_minimum_required(VERSION 2.8.12)
add_definitions("-fPIC")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()


include_directories(${CMAKE_INCLUDE_PATH})
add_executable(rtype mainMenu.cpp menu.cpp menu.hpp player.hpp player.cpp Iplayer.hpp mainGame.cpp mainGame.hpp Ishoot.hpp shoot.hpp shoot.cpp ennemies.cpp ennemies.hpp)
target_link_libraries(rtype ${CONAN_LIBS})