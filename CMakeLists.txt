cmake_minimum_required(VERSION 3.6)
project(LidarVisualisation)

set(CMAKE_CXX_STANDARD 11)
set(SRC src/main.cpp src/CoordinateGrid.cpp src/TitleStatus.cpp src/Obstacle.cpp)
add_executable(LidarVisualisation.exe ${SRC})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML COMPONENTS graphics window network audio system REQUIRED)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(LidarVisualisation.exe ${SFML_LIBRARIES})
endif()