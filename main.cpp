#include "MainSDLWindow.hpp"
#include "Snake.hpp"
#include <SDL2/SDL.h>

int main (void) {
    int frame_delay;
    int frame_rate_ms = 20 ;
    Uint32 frame_start;
    int playing = 1;
    SDL_Event event;
    MainSDLWindow sdlwin;
    SDL_Renderer* renderer; 
    sdlwin.Init("Snake", 600, 480);
    Snake* s = new Snake(300, 240, UP);
    do{
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                playing = 0;
            }    
        }
        s->keyboard();
        s->Move();
        s->Draw(renderer);
        frame_delay = frame_rate_ms - (SDL_GetTicks() - frame_start);
        if (frame_delay > 0)
        SDL_Delay(frame_delay);
    }while(playing==1);
    return 0;
}