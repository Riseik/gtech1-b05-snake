#include "Snake.hpp"

Snake::Snake() {

}

Snake::~Snake() {

}

void Snake::keyboard() {
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    switch

    if (keystates[SDL_SCANCODE_UP]) {
        posy+=60;
    }
    if (keystates[SDL_SCANCODE_DOWN]) {
        posy-=60;
    }
    if (keystates[SDL_SCANCODE_LEFT]) {
        posx-=60;
    }
    if (keystates[SDL_SCANCODE_RIGHT]) {
        posx+=60;
    }
}