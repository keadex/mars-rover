#pragma once
#include <string>
#include <type_traits>
#include <vector>
#include <memory> 
#include "IMissionParser.h"
#include "../robot/AbstractRobot.h"

namespace Mission {

    template<typename P, typename R, typename C>
    class AbstractMission {
        static_assert(std::is_base_of<Robot::AbstractController, C>::value, "C must inherit from AbstractController");
        static_assert(std::is_base_of<Robot::AbstractRobot<C>, R>::value, "R must inherit from AbstractRobot<R>");
        static_assert(std::is_base_of<IMissionParser<R, C>, P>::value, "P must inherit from IMissionParser<R, C>");
        std::vector<R> robots;
        
        protected:
            std::unique_ptr<P> missionParser;  
        
        public:
            AbstractMission(const std::string mission);
            virtual ~AbstractMission(){};
            void run();
            int numRobots() const;
            R robot(int index);
    };

}