#include "AbstractController.h"
#include "Position.h"
#include "Plateau.h"
#include <string>

namespace Robot {
    AbstractController::AbstractController(){}
    
    AbstractController::AbstractController(const Position& initialPosition, const Plateau& plateau){
        currentPosition = initialPosition;
        this->plateau = plateau; 
    }

    void AbstractController::executeCommands(const std::string& commands){
        for (auto const& command : commands) {
            switch (command){
                case MOVE_FORWARD_COMMAND:
                    moveForward();
                    break;
                case TURN_LEFT_COMMAND:
                    turnLeft();
                    break;
                case TURN_RIGHT_COMMAND:
                    turnRight();
                    break;
            } 
        }
    }

    Position AbstractController::position(){
        return currentPosition;
    }

    void AbstractController::changePosition(const Position& changedPosition){
        currentPosition = changedPosition;
    }

    void AbstractController::errorOccurred() {
        this->error = true;
    }

    bool AbstractController::hasAnError() {
        return this->error;
    }
}