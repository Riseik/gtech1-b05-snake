#include "snake.hpp"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "MainSDLWindow.hpp"

Snake::Snake(){

}
Snake::~Snake(){

}
int Snake::Draw(){
    SDL_SetRenderDrawColor(renderer,0,0,0,0);
    SDL_RenderClear(renderer);
    rectX = 0;
    rectY = 0;
    int SDL_RenderDrawRect(SDL_Renderer * renderer,const SDL_Rect * rect);
  
    
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    
    SDL_RenderPresent(renderer);
}

void Snake::PollEvent()
{
  SDL_Event event;
  while (SDL_PollEvent(&event))
  {
    if(event.type == SDL_QUIT)
    {
      run = false;
    }
    else if (event.type == SDL_KEYDOWN)
    {
      switch(event.key.keysym.sym)
      {
        case SDLK_UP:
          if(lmove != move::down)
          dir = move::up;
        break;

        case SDLK_DOWN:
          if(lmove != move::up)
          dir = move::down;
        break;

        case SDLK_LEFT:
          if(lmove != move::right)
          dir = move::left;
        break;

        case SDLK_RIGHT:
          if(lmove != move::left)
          dir = move::right;
        break;

      }
    }
  }
}
