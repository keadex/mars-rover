#include <iostream>
#include "AbstractRobot.h"
#include <string>
#include "../mars-rover/MarsRoverController.h"

namespace Robot {

    template<typename C>
    AbstractRobot<C>::AbstractRobot(const C& robotController, const std::string& commands){
        this->robotController = C(robotController);
        this->commands = std::string(commands);
    }

    template<typename C>
    C AbstractRobot<C>::controller(){
        return robotController;
    }
    
    template<typename C>
    void AbstractRobot<C>::run(){
        robotController.executeCommands(commands);
        Robot::Position changedPosition = robotController.position();
    }
    
    template class AbstractRobot<MarsRoverController>;
}