#include "MarsRoverController.h"
#include "../robot/AbstractController.h"
#include "../robot/Position.h"
#include "../robot/Plateau.h"
#include "../exception/error.h"
#include <memory>

MarsRoverController::MarsRoverController(): Robot::AbstractController(){};

MarsRoverController::MarsRoverController(const Robot::Position& initialPosition, const Robot::Plateau& plateau)
    : Robot::AbstractController(initialPosition, plateau){};

void MarsRoverController::moveForward(){
    std::unique_ptr<Robot::Position> changedPosition;
    
    switch(position().getDirection()){
        case Robot::NORTH:
            changedPosition = std::make_unique<Robot::Position>(position().getX(), position().getY()+1, position().getDirection());
            break;
        case Robot::EAST:
            changedPosition = std::make_unique<Robot::Position>(position().getX()+1, position().getY(), position().getDirection());
            break;
        case Robot::SOUTH:
            changedPosition = std::make_unique<Robot::Position>(position().getX(), position().getY()-1, position().getDirection());
            break;
        case Robot::WEST:
            changedPosition = std::make_unique<Robot::Position>(position().getX()-1, position().getY(), position().getDirection());
            break;
    }
    if (changedPosition){
        changePosition(*changedPosition.get());
        validatePosition(*changedPosition.get());
    }            
};

void MarsRoverController::turnLeft(){
    std::unique_ptr<Robot::Position> changedPosition
        = std::make_unique<Robot::Position>(position().getX(), position().getY(), Robot::WindRose::integerToCardinalDirection((position().getDirection()+3)%4));
    changePosition(*changedPosition.get());
};

void MarsRoverController::turnRight(){
    std::unique_ptr<Robot::Position> changedPosition
        = std::make_unique<Robot::Position>(position().getX(), position().getY(), Robot::WindRose::integerToCardinalDirection((position().getDirection()+1)%4));
    changePosition(*changedPosition.get());
};

void MarsRoverController::validatePosition(const Robot::Position& position){
    validateX(position.getX());
    validateY(position.getY());
};

void MarsRoverController::validateX(const int x) {
    if (x < 0 || x >= this->plateau.getWidth()){
        errorOccurred();
        throw std::runtime_error(Error::ERROR_INVALID_ROVER_X_POSITION);
    }
};

void MarsRoverController::validateY(const int y) {
    if (y < 0 || y >= this->plateau.getHeight()){
        errorOccurred();
        throw std::runtime_error(Error::ERROR_INVALID_ROVER_Y_POSITION);
    }
};