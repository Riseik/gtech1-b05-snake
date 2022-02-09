#include <SDL2/SDL.h>
#include "MainSDLWindow.hpp"

#ifndef SNAKE_HPP
#define SNAKE_HPP

#define HEAD_SIZE 30

class Snake {
    public:

        Snake();
        ~Snake();
        int Draw();
        
        int print();
        int drawHead(int RectSize, SDL_Renderer *renderer);
        int keyEnter();
        

    private:
        enum class move {up, down, left,right};
        move lmove = move::up;
        move dir = move::up;
        void PollEvent();
        bool run = false;
        SDL_Renderer *renderer;
        int rectX;
        int rectY;

        

}

#endif