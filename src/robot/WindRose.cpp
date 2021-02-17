#include "WindRose.h"
#include <stdexcept>
#include "../exception/error.h"

namespace Robot{
    char WindRose::cardinalDirectionToCharacter(CardinalDirection direction) {
        return WIND_ROSE[direction];
    }

    CardinalDirection WindRose::characterToCardinalDirection(char character) {
        for (int i=0; i<4; i++){
            if (WIND_ROSE[i]== character) return static_cast<CardinalDirection>(i);
        }
        throw std::runtime_error(Error::ERROR_INVALID_CARDINAL_DIRECTION_CHAR);
    }

    CardinalDirection WindRose::integerToCardinalDirection(int integer) {
        if (integer >= 0 && integer < 4)
            return static_cast<CardinalDirection>(integer);
        throw std::runtime_error(Error::ERROR_INVALID_CARDINAL_DIRECTION_NUMBER);
    }

    CardinalDirection WindRose::stringToCardinalDirection(std::string string) {
        if (string.length() != 1)
            throw std::runtime_error(Error::ERROR_INVALID_CARDINAL_DIRECTION_STRING);
        return WindRose::characterToCardinalDirection(string.at(0));
    }
}