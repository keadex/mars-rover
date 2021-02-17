#pragma once
#include <string>
#include "../../src/mission/AbstractMission.h"
#include "../../src/mars-rover/MarsMissionParser.h"
#include "../../src/mars-rover/MarsRover.h"
#include "../../src/mars-rover/MarsRoverController.h"

class MarsMission : public Mission::AbstractMission<MarsMissionParser, MarsRover, MarsRoverController> {
    public:
        MarsMission(const std::string mission);
        ~MarsMission(){};
};
