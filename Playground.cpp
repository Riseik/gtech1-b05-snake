#include "Playground.hpp"
#include "constants.h"

Playground::Playground() {
   this->nbrow = nbrow;
   this->nbcol = nbcol;
}

Playground::~Playground() {
    
}

int Playground::Init(int nbrow, int nbcol, SDL_Renderer* renderer) {
    int Color = 0;
    int row;
    int col;
    for (row = 0; row < nbrow; row ++)
    {
        Color -= 1;
        for (col = 0; col < nbcol; col ++)
        {
            if (Color == 0)
            {
                SDL_SetRenderDrawColor(renderer, 0, 0, 121, 255);
                Color = 1;
            }
            else
            {
                SDL_SetRenderDrawColor(renderer, 0, 0, 56, 255);
                Color = 0;
            }

            SDL_Rect rectangle = {row * SNAKE_SIZE, col * SNAKE_SIZE, SNAKE_SIZE, SNAKE_SIZE};

            SDL_RenderFillRect(renderer, &rectangle);
        }
    }
    return 0;
}

