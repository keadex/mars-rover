#include "gtest/gtest.h"
#include "../include/mars-rover/MarsMission.h"
#include "../src/exception/error.h"
#include "../src/exception/error.h"
#include "../src/robot/Position.h"

TEST(MarsMissionTester, MissionWithoutPlateauSize){
  std::string missionInput = "1 2 N\nLMLMLMLMM\n3 3 E\nMMRMMRMRRM";
  
  try{
    MarsMission *marsMission = new MarsMission(missionInput);
    FAIL() << "Expected std::runtime_error";
  }catch (std::runtime_error const & err){
    EXPECT_EQ(err.what(),std::string(Error::ERROR_INVALID_PLATEAU_SIZE));
  }catch(...) {
    FAIL() << "Expected std::runtime_error";
  }
}

TEST(MarsMissionTester, MissionWithInvalidRoverPosition){
  std::string missionInput = "5 5\n1 2 N 2\nLMLMLMLMM";
  
  try{
    MarsMission *marsMission = new MarsMission(missionInput);
    FAIL() << "Expected std::runtime_error";
  }catch (std::runtime_error const & err){
    EXPECT_EQ(err.what(),std::string(Error::ERROR_INVALID_POSITION));
  }catch(...) {
    FAIL() << "Expected std::runtime_error";
  }
}

TEST(MarsMissionTester, MissionWithInvalidCardinalDirectionChar){
  std::string missionInput = "5 5\n1 2 G\nLMLMLMLMM";
  
  try{
    MarsMission *marsMission = new MarsMission(missionInput);
    FAIL() << "Expected std::runtime_error";
  }catch (std::runtime_error const & err){
    EXPECT_EQ(err.what(),std::string(Error::ERROR_INVALID_CARDINAL_DIRECTION_CHAR));
  }catch(...) {
    FAIL() << "Expected std::runtime_error";
  }
}

TEST(MarsMissionTester, MissionWithInvalidCommand){
  std::string missionInput = "5 5\n1 2 N\nLMLMLMLMG";
  
  try{
    MarsMission *marsMission = new MarsMission(missionInput);
    FAIL() << "Expected std::runtime_error";
  }catch (std::runtime_error const & err){
    EXPECT_EQ(err.what(),std::string(Error::ERROR_INVALID_COMMAND));
  }catch(...) {
    FAIL() << "Expected std::runtime_error";
  }
}

TEST(MarsMissionTester, MissionHasOneRover){
  std::string missionInput = "5 5\n1 2 N\nLMLMLMLMM";
  
  MarsMission *marsMission = new MarsMission(missionInput);
  
  EXPECT_EQ(marsMission->numRobots(), 1);
}

TEST(MarsMissionTester, MissionHasTwoRovers){
  std::string missionInput = "5 5\n1 2 N\nLMLMLMLMM\n3 3 E\nMMRMMRMRRM";
  
  MarsMission *marsMission = new MarsMission(missionInput);
  
  EXPECT_EQ(marsMission->numRobots(), 2);
}

TEST(MarsMissionTester, RoverMovesOutOfPlateauHeight){
  int plateauWidth = 5;
  int plateauHeight = 5;

  std::string missionInput = std::to_string(plateauWidth) + " " + std::to_string(plateauHeight) + "\n1 2 N\nMMMMMMM";
  MarsMission *marsMission = new MarsMission(missionInput);
  marsMission->run();
  
  ASSERT_GT(marsMission->robot(0).controller().position().getY(), plateauHeight);
}

TEST(MarsMissionTester, RoverMovesOutOfPlateauWidth){
  int plateauWidth = 5;
  int plateauHeight = 5;
  std::string missionInput = std::to_string(plateauWidth) + " " + std::to_string(plateauHeight) + "\n1 2 E\nMMMMMMM";
  
  MarsMission *marsMission = new MarsMission(missionInput);
  marsMission->run();
  
  ASSERT_GT(marsMission->robot(0).controller().position().getX(), plateauWidth);
}

TEST(MarsMissionTester, VerifyOneRoverHasCorrectFinalPosition){
  int plateauWidth = 5;
  int plateauHeight = 5;
  int initialRoverXPosition = 1;
  int initialRoverYPosition = 2;
  char initialRoverCardinalDirection = 'N';
  std::string command = "LMLMLMLMM";
  Robot::Position expectedPosition = Robot::Position(1, 3, Robot::CardinalDirection::NORTH);
  std::string missionInput = std::to_string(plateauWidth) + " " + std::to_string(plateauHeight) + "\n"
    + std::to_string(initialRoverXPosition) + " " + std::to_string(initialRoverYPosition) + " " + initialRoverCardinalDirection + "\n"
    + command ;

  MarsMission *marsMission = new MarsMission(missionInput);
  marsMission->run();
  
  EXPECT_EQ(marsMission->robot(0).controller().position(), expectedPosition);
}

TEST(MarsMissionTester, VerifyTwoRoversHaveCorrectFinalPosition){
  int plateauWidth = 5;
  int plateauHeight = 5;
  int initialRoversXPosition[2] = {1, 3};
  int initialRoversYPosition[2] = {2, 3};
  char initialRoversCardinalDirection[2] = {'N', 'E'};
  std::string commands[2] = {"LMLMLMLMM", "MMRMMRMRRM"};
  Robot::Position expectedPositions[2] = {Robot::Position(1, 3, Robot::CardinalDirection::NORTH), Robot::Position(5, 1, Robot::CardinalDirection::EAST)};
  std::string missionInput = std::to_string(plateauWidth) + " " + std::to_string(plateauHeight);
  for (int i=0; i<2; i++){
    missionInput += "\n" + std::to_string(initialRoversXPosition[i]) + " " + std::to_string(initialRoversYPosition[i]) + " " + initialRoversCardinalDirection[i] + "\n"
    + commands[i] ;
  }

  MarsMission *marsMission = new MarsMission(missionInput);
  marsMission->run();

  for (int i=0; i<marsMission->numRobots(); i++){
    EXPECT_EQ(marsMission->robot(i).controller().position(), expectedPositions[i]);
  }
}