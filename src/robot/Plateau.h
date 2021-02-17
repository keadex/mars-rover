#pragma once

namespace Robot {
    class Plateau {
        int width, height;
        public:
            Plateau();
            Plateau(int width, int height);
            int getWidth() const;
            int getHeight() const;
    };
}