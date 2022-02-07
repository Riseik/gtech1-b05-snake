#include "Playground.hpp"

Playground::Playground(int nbrow, int nbcol) {
    int Color = 0;
    for (this->nbrow = 0; this->nbrow < 10; this->nbrow += 1)
    {
        for (this->nbcol = 0; this->nbcol < 10; this->nbcol += 1)
        {
            if (Color == 0)
            {
                SDL_SetRenderDrawColor(SDL_Renderer *renderer, 255, 100, 100, 255);
                Color = 1;
            }
            else
            {
                SDL_SetRenderDrawColor(SDL_Renderer *renderer, 255, 200, 200, 255);
                Color = 0;
            }

            SDL_Rect rectangle;
            rectangle.w = 60;
            rectangle.h = 60;
            rectangle.x = x;
            rectangle.y = y;

            SDL_RenderFillRect(SDL_Renderer *renderer, &rectangle);
        }
    }
}

Playground::~Playground() {
    
}

Playground::Init() {
    
}

