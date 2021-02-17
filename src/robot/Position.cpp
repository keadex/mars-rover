#include "Position.h"
#include "WindRose.h"

namespace Robot{
    Position::Position(){}

    Position::Position(const int x, const int y, const CardinalDirection direction){
        this->x = x;
        this->y = y;
        this->direction = direction;
    }

    int Position::getX() const {
        return x;
    }

    int Position::getY() const{
        return y;
    }

    CardinalDirection Position::getDirection() const{
        return direction;
    }

    Position& Position::operator=(const Position& other){
        x = other.x;
        y = other.y;
        direction = other.direction;
        return *this;
    }

    std::ostream& operator<<(std::ostream& os, const Position& position){
        os << position.getX() << ' ' << position.getY() << ' ' << Robot::WindRose::cardinalDirectionToCharacter(position.getDirection());
        return os;
    }

    bool Position::operator==(const Position& other) const{
        return x == other.x && y == other.y && direction == other.direction;
    }
}