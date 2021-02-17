#include "MarsRover.h"
#include "MarsRoverController.h"
#include "../robot/AbstractRobot.h"
#include <string>


MarsRover::MarsRover(const MarsRoverController& robotController, const std::string& commands)
    :Robot::AbstractRobot<MarsRoverController>::AbstractRobot(robotController, commands){};

