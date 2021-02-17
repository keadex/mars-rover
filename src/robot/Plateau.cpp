#include "Plateau.h"

namespace Robot{ 
  Plateau::Plateau() {}

  Plateau::Plateau(int width, int height) {
    this->width = width;
    this->height = height;
  }

  int Plateau::getWidth() const{
    return width;
  }

  int Plateau::getHeight() const{
    return height;
  }
}