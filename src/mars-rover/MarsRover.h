#pragma once
#include "MarsRoverController.h"
#include "../robot/AbstractRobot.h"
#include <string>

class MarsRover : public Robot::AbstractRobot<MarsRoverController>{
    public:
        MarsRover(const MarsRoverController& marsRoverController, const std::string& commands);
        using Robot::AbstractRobot<MarsRoverController>::AbstractRobot; // inherit the constructor
        ~MarsRover(){};
};