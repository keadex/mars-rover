#pragma once
#include <string>

namespace Robot {
    static const char WIND_ROSE[4] = {'N', 'E', 'S', 'W'};
    enum CardinalDirection {NORTH, EAST, SOUTH, WEST};

    class WindRose {
        public:
            static char cardinalDirectionToCharacter(CardinalDirection direction);
            static CardinalDirection characterToCardinalDirection(char character);
            static CardinalDirection integerToCardinalDirection(int integer);
            static CardinalDirection stringToCardinalDirection(std::string string);
        private:
            WindRose() {}
    };
}