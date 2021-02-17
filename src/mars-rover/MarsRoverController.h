#pragma once
#include "../robot/AbstractController.h"
#include "../robot/Position.h"
#include "../robot/Plateau.h"

class MarsRoverController : public Robot::AbstractController {
   
    public:
        MarsRoverController();
        MarsRoverController(const Robot::Position& initialPosition, const Robot::Plateau& plateau);
        virtual ~MarsRoverController(){};
    private:
        void validateX(const int x);
        void validateY(const int y);
        virtual void moveForward();
        virtual void turnLeft();
        virtual void turnRight();
        virtual void validatePosition(const Robot::Position& changedPosition);
};