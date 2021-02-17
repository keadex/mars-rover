#pragma once
#include "../mission/IMissionParser.h"
#include "MarsRoverController.h"
#include "MarsRover.h"
#include <vector>
#include <memory>

class MarsMissionParser : public Mission::IMissionParser<MarsRover, MarsRoverController> {

    public:
        virtual ~MarsMissionParser(){};
        virtual void parse(const std::string mission, std::vector<MarsRover>& marsRovers);
    private:
        std::unique_ptr<Robot::Plateau> initPlateauFromString(const std::string string);
        std::unique_ptr<Robot::Position> initPositionFromString(const std::string string);
        void validateCommands(const std::string& string);
};