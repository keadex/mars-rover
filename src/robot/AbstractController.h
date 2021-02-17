#pragma once
#include "Plateau.h"
#include "Position.h"
#include <string>

namespace Robot {
    static const char MOVE_FORWARD_COMMAND = 'M';
    static const char TURN_LEFT_COMMAND = 'L';
    static const char TURN_RIGHT_COMMAND = 'R';
    static const char END_COMMAND = '\n';
    
    class AbstractController {
        virtual void moveForward() = 0;
        virtual void turnLeft() = 0;
        virtual void turnRight() = 0;
        virtual void validatePosition(const Position& changedPosition) = 0;
        bool error = false;
        
        protected:
            Position currentPosition = Position();
            Plateau plateau = Plateau();
        
        public:
            AbstractController();
            AbstractController(const Position& initialPosition, const Plateau& plateau);
            virtual ~AbstractController(){};
            void executeCommands(const std::string& commands);
            Position position();
            void changePosition(const Position& changedPosition);
            void errorOccurred();
            bool hasAnError();              
    };
}