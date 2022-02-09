#include "MainSDLWindow.hpp"
#include "Snake.hpp"
#include "Playground.hpp"
#include <SDL2/SDL.h>

int main (void) {
    MainSDLWindow sdlwin;
    SDL_Renderer* renderer;
    //Fruits* fr;
    //Snake* sn = new Snake(WIDTH / 2, HEIGHT / 2, UP);
    Playground* pg;
    SDL_Event event;

    int frame_rate = 20 ;

    int playing = 1;
    pg->Init(renderer);  
     
    //sdlwin.Init("Snake", 600, 480);
    
    do{

        Uint32 frame_time_start = SDL_GetTicks();

        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                playing = 0;
            }    
        }
       /* sn->keyboard();
        sn->Move();
        sn->Draw(renderer); */
        pg->Init(renderer);

        Uint32 frame_time_interval = SDL_GetTicks() - frame_time_start;
        if (frame_time_interval < frame_rate)
        {   
            SDL_Delay(frame_rate - frame_time_interval);
        }
    }while(playing==1);
    return 0;
}