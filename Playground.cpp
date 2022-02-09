#include "Playground.hpp"

Playground::Playground(int nbrow, int nbcol) {
   this->nbrow;
   this->nbcol;
   this->renderer;
}

Playground::~Playground() {
    
}

int Playground::Init() {
    int Color = 0;
    for (nbrow = 0; nbrow < 10; nbrow += 1)
    {
        for (nbcol = 0; nbcol < 10; nbcol += 1)
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
            rectangle.w = 60;
            rectangle.h = 60;
            rectangle.x = nbrow;
            rectangle.y = nbcol;

            SDL_RenderFillRect(renderer, &rectangle);
        }
    }
}

