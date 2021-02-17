#pragma once
#include "../robot/AbstractRobot.h"
#include <string>
#include <vector>

namespace Mission {

    template<class R, class C>
    class IMissionParser {
        static_assert(std::is_base_of<Robot::AbstractRobot<C>, R>::value, "R must inherit from AbstractRobot<R>");
        public:
            virtual ~IMissionParser(){};
            virtual void parse(const std::string mission, std::vector<R>& robots) = 0;                
    };
    
}