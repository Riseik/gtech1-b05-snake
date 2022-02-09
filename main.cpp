#include "MainSDLWindow.hpp"
#include "Snake.hpp"
#include "Playground.hpp"
#include "Fruits.hpp"
#include "constants.h"
#include <SDL2/SDL.h>

int main (void) {
    int lenght = 1;
    
    MainSDLWindow sdlwin;
    Fruits* fr = new Fruits();
    Snake* sn = new Snake(WIDTH / 2, HEIGHT / 2, UP, lenght);
    Segment* seg;
    Playground* pg = new Playground();
    SDL_Event event;

    int frame_rate = 122 ;

    int playing = 1;
    
     
    sdlwin.Init("Snake", WIDTH, HEIGHT);
    
    SDL_Renderer* renderer = sdlwin.GetRenderer();
    do{
        Uint32 frame_time_start = SDL_GetTicks();
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
    
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                playing = 0;
            }    
        }
        pg->Init(WIDTH / SNAKE_SIZE, HEIGHT / SNAKE_SIZE, renderer);
        if(fr->GetX() == sn->GetHead()->GetX() && fr->GetY() == sn->GetHead()->GetY()) {
            Segment* create = sn->GetHead();
            while(create != NULL){
                create = create->GetNext();
            }
            Segment* next = new Segment(seg->GetX(), seg->GetY(), seg->GetDir(), NULL);
            fr->RandX();
            fr->RandY();
        }
        fr->Draw(renderer);
        sn->keyboard();
        sn->Move();
        sn->Draw(renderer);
        playing = sn->Collide();
        
        
        SDL_RenderPresent(renderer);
        Uint32 frame_time_interval = SDL_GetTicks() - frame_time_start;
        if (frame_time_interval < frame_rate)
        {   
            SDL_Delay(frame_rate - frame_time_interval);
        }
    }while(playing==1);
    return 0;
}