#include "AbstractMission.h"
#include <memory> 
#include <vector> 
#include "../mars-rover/MarsMissionParser.h"
#include "../mars-rover/MarsRover.h"
#include "../mars-rover/MarsRoverController.h"
#include <iostream>
#include <exception>

namespace Mission {

    template<typename P, typename R, typename C>
    AbstractMission<P, R, C>::AbstractMission(const std::string mission){
        robots = std::vector<R>();
        this->missionParser = std::make_unique<P>();
        this->missionParser->parse(mission, robots);
    }

    template<typename P, typename R, typename C>
    void AbstractMission<P, R, C>::run(){
        for (auto &robot : robots) {
            try{
                robot.run();
            }catch (std::exception& e){
                //nop
            }            
        }
    }

    template<typename P, typename R, typename C>
    int AbstractMission<P, R, C>::numRobots() const{
        return this->robots.size();
    }

    template<typename P, typename R, typename C>
    R AbstractMission<P, R, C>::robot(int index) {
        return this->robots.at(index);
    }

    template class AbstractMission<MarsMissionParser, MarsRover, MarsRoverController>;

}