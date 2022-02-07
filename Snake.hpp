#pragma once
#include <SDL2/SDL.h>

class Snake {
public:
  Snake();
  ~Snake();
  void keyboard();
private:
  int nbrow;
  int nbcol;
};