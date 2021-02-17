#include "../../include/mars-rover/MarsMission.h"
#include "MarsRover.h"
#include "MarsRoverController.h"
#include "MarsMissionParser.h"
#include "../mission/AbstractMission.h"
#include <memory>

MarsMission::MarsMission(const std::string mission): 
    Mission::AbstractMission<MarsMissionParser, MarsRover, MarsRoverController>
        ::AbstractMission(mission){};