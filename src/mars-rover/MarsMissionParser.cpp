#include "MarsMissionParser.h"
#include "MarsRover.h"
#include "MarsRoverController.h"
#include "../robot/Position.h"
#include "../robot/Plateau.h"
#include <vector>
#include <sstream>
#include <iostream>
#include <memory>
#include <exception>
#include "../utils/Utils.h"
#include "../exception/error.h"

void MarsMissionParser::parse(const std::string mission, std::vector<MarsRover>& marsRovers){
    std::istringstream f(mission);

    std::unique_ptr<Robot::Plateau> plateau;
    std::unique_ptr<Robot::Position> initialPosition;

    std::string line;
    int numLine = 1;

    while (std::getline(f, line)) {        
        if (numLine == 1){
            plateau = initPlateauFromString(line);
        }else if ((numLine%2)==0){
            initialPosition = initPositionFromString(line);
        }else if ((numLine%2)==1){
            validateCommands(line);

            MarsRoverController controller = MarsRoverController(*initialPosition.get(), *plateau.get());
            marsRovers.push_back(MarsRover(controller, line));

            if (initialPosition.get()) initialPosition.reset();
        }        

        numLine++;
    }

    if (plateau.get()) plateau.reset();
}


std::unique_ptr<Robot::Plateau> MarsMissionParser::initPlateauFromString(const std::string string) {
    std::vector<std::string> values = Utils::StringUtils::splitBySpace(string);
    try{
        if (values.size() != 2) throw std::runtime_error("");
        int x = std::stoi(values.at(0));
        int y = std::stoi(values.at(1));
        return std::make_unique<Robot::Plateau>(x+1, y+1);
    }catch (std::exception& e){
        throw std::runtime_error(Error::ERROR_INVALID_PLATEAU_SIZE);
    }     
}

std::unique_ptr<Robot::Position> MarsMissionParser::initPositionFromString(const std::string string) {
    std::vector<std::string> values = Utils::StringUtils::splitBySpace(string);
    try{
        if (values.size() != 3) throw std::invalid_argument("");
        int x = std::stoi(values.at(0));
        int y = std::stoi(values.at(1));
        Robot::CardinalDirection cardinalDirection = Robot::WindRose::stringToCardinalDirection(values.at(2));
        return std::make_unique<Robot::Position>(x, y, cardinalDirection);
    }catch (std::invalid_argument &e){
        throw std::runtime_error(Error::ERROR_INVALID_POSITION);
    }
}

void MarsMissionParser::validateCommands(const std::string& string) {
    
    for (int i=0; i<string.length(); i++){
        char character = string.at(i);
        if ((character != Robot::MOVE_FORWARD_COMMAND && character != Robot::TURN_LEFT_COMMAND
        && character != Robot::TURN_RIGHT_COMMAND) || (character == Robot::END_COMMAND && i != (string.length()-1))){
            throw std::runtime_error(Error::ERROR_INVALID_COMMAND);
        }
    }
}