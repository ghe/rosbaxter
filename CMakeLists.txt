cmake_minimum_required(VERSION 2.8.3)
project(rosbaxter)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp std_msgs sensor_msgs)

## Declare a catkin package
#catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_library(rosbaxter src/rosbaxter.cpp src/currentpose.cpp)
target_link_libraries(rosbaxter ${catkin_LIBRARIES})

add_executable(rosbaxtertest src/main.cpp)
target_link_libraries(rosbaxtertest rosbaxter)
