#pragma once
#include "AbstractController.h"
#include <string>
#include <type_traits>
#include <string>

namespace Robot {
    
    template<class C>
    class AbstractRobot {
        static_assert(std::is_base_of<AbstractController, C>::value, "C must inherit from Robot::AbstractController");        
        C robotController;
        std::string commands;
        
        public:
            AbstractRobot(const C& robotController, const std::string& commands);
            virtual ~AbstractRobot(){};
            C controller();
            void run();
    };

}