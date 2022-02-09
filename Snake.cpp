#include "Snake.hpp"

Segment::Segment(int x, int y) {
    this->x = x;
    this->y = y;
}

Segment::~Segment() {

}

void Segment::SetDir(Direction dir) {
  this->dir = dir;
}

Direction Segment::GetDir() {
    return dir;
}

Segment* Segment::GetNext() {
    return this->next;
}

int Segment::GetX() {
    return x;
}

int Segment::GetY() {
    return y;
}

Snake::Snake(int x, int y, Direction dir) {
    this->x = x;
    this->y = y;
    this->dir = dir;
}

Snake::~Snake() {

}

Segment* Snake::GetHead() {
    return head;
}

void Snake::keyboard() {
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);

    if (keystates[SDL_SCANCODE_UP]) {
        head->SetDir(UP);
    }
    if (keystates[SDL_SCANCODE_DOWN]) {
        head->SetDir(DOWN);
    }
    if (keystates[SDL_SCANCODE_LEFT]) {
        head->SetDir(LEFT);
    }
    if (keystates[SDL_SCANCODE_RIGHT]) {
        head->SetDir(RIGHT);
    }
}

void Snake::Move() {
    switch (head->GetDir())
	{

	case UP:    
        this->y--; 
        break;

	case DOWN:  
        this->y++; 
        break;

	case LEFT:  
        this->x--; 
        break;

	case RIGHT: 
        this->x++; 
        break;

	}
}

void Snake::Draw(SDL_Renderer* renderer) {
    SDL_Rect rect = {this->head->GetX(), this->head->GetY(), 50, 50};
    SDL_SetRenderDrawColor(renderer, 255, 200, 200, 255);
    printf("Couleur");
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
    printf("affiché");
    SDL_RenderPresent(renderer);
    SDL_Delay(500);
}