#include "MainSDLWindow.hpp"
#include <SDL2/SDL.h>

int main (void) {
    MainSDLWindow sdlwin;
    sdlwin.Init("Snake", 600, 480);
    SDL_Delay(3000);
    return 0;
}