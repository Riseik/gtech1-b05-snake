#pragma once
#include <SDL2/SDL.h>

class MainSDLWindow {
public:
  MainSDLWindow();
  ~MainSDLWindow();
  SDL_Renderer *GetRenderer();
  int Init(const char* winname, int width_, int height_);

private:
  SDL_Renderer *renderer;
  SDL_Window *window;
};