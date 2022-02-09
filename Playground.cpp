#include "Playground.hpp"

Playground::Playground(int nbrow, int nbcol) {
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
        for (col = 0; col < nbcol; col ++)
        {
            if (Color == 0)
            {
                SDL_SetRenderDrawColor(renderer, 255, 100, 100, 255);
                Color = 1;
            }
            else
            {
                SDL_SetRenderDrawColor(renderer, 255, 200, 200, 255);
                Color = 0;
            }

            SDL_Rect rectangle;
            rectangle.w = 30;
            rectangle.h = 30;
            rectangle.x = row;
            rectangle.y = col;

            SDL_RenderFillRect(renderer, &rectangle);
        }
    }
    return 0;
}

