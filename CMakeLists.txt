cmake_minimum_required(VERSION 3.0.2)
project (SmartBuoy)

add_definitions(-std=c++0x)

add_executable(main main.cpp myLCD.cpp myGSM.cpp)

target_link_libraries(main wiringPi)
