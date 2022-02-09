#include "Fruits.hpp"
#include "Snake.hpp"
#include "constants.h"

Fruits::Fruits() {
    this->RandX();
    this->RandY();
}

Fruits::~Fruits() {

}

int Fruits::GetX() {
    return xf;
}

int Fruits::GetY() {
    return yf;
}

int Fruits::RandX() {
    this->xf = (rand() % (WIDTH / SNAKE_SIZE)) * SNAKE_SIZE;
    return xf;
}

int Fruits::RandY() {
    this->yf = (rand() % (HEIGHT / SNAKE_SIZE)) * SNAKE_SIZE;
    return yf;
}

void Fruits::Draw(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 176, 0, 0, 255);
    SDL_Rect rect = {xf, yf, SNAKE_SIZE, SNAKE_SIZE};
    SDL_RenderFillRect(renderer, &rect);
}