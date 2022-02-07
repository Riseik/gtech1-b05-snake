#pragma once
#include <SDL2/SDL.h>

class Playground {
public:
  Playground(int nbrow, int nbcol);
  ~Playground();
private:
  int nbrow;
  int nbcol;
};