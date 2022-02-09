#pragma once
#include <SDL2/SDL.h>

class Playground {
public:
  Playground(int nbrow, int nbcol);
  ~Playground();
  SDL_Renderer *GetRenderer();
  int Init();
private:
  int nbrow;
  int nbcol;
};