#pragma once
#include <ostream>
#include "WindRose.h"

namespace Robot {

    class Position {
        int x, y;
        CardinalDirection direction;

        public:
            Position();
            Position(const int x, const int y, const CardinalDirection direction);
            int getX() const;
            int getY() const;
            CardinalDirection getDirection() const;
            Position& operator=(const Position& other);
            bool operator==(const Position& other) const;
    };

    std::ostream& operator<<(std::ostream& os, const Position& position);
}