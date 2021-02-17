cmake_minimum_required(VERSION 3.0.0)
project(marsrover VERSION 0.1.0)

enable_testing()
include(CTest)
find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(marsrover main.cpp src/mars-rover/MarsMission.cpp src/mars-rover/MarsMissionParser.cpp
 src/mars-rover/MarsRover.cpp src/mars-rover/MarsRoverController.cpp src/mission/AbstractMission.cpp 
 src/robot/AbstractController.cpp src/robot/AbstractRobot.cpp src/robot/Plateau.cpp src/robot/Position.cpp 
 src/robot/WindRose.cpp src/utils/Utils.cpp)

add_executable(tests tests/mars_mission_tester.cpp src/mars-rover/MarsMission.cpp src/mars-rover/MarsMissionParser.cpp
src/mars-rover/MarsRover.cpp src/mars-rover/MarsRoverController.cpp src/mission/AbstractMission.cpp 
src/robot/AbstractController.cpp src/robot/AbstractRobot.cpp src/robot/Plateau.cpp src/robot/Position.cpp 
src/robot/WindRose.cpp src/utils/Utils.cpp)
target_link_libraries(tests GTest::GTest GTest::Main)
gtest_discover_tests(tests)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)