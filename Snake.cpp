#include "Snake.hpp"
#include "constants.h"

Segment::Segment(int x, int y, Direction dir, Segment *next)
{
    this->x = x;
    this->y = y;
    this->dir = dir;
    this->next = NULL;
}

Segment::~Segment()
{
}

void Segment::SetDir(Direction dir)
{
    this->dir = dir;
}

Direction Segment::GetDir()
{
    return dir;
}

Segment *Segment::GetNext()
{
    return next;
}

void Segment::SetNext(Segment* next){
    this->next = next;
}

int Segment::GetX()
{
    return x;
}

int Segment::GetY()
{
    return y;
}

int Segment::AddX()
{
    return x += SNAKE_SIZE;
}

int Segment::AddY()
{
    return y += SNAKE_SIZE;
}

int Segment::SubX()
{
    return x -= SNAKE_SIZE;
}

int Segment::SubY()
{
    return y -= SNAKE_SIZE;
}

Snake::Snake(int x, int y, Direction dir, int lenght)
{
    head = new Segment(x, y, dir, NULL);
}

Snake::~Snake()
{
}

Segment *Snake::GetHead()
{
    return head;
}

void Snake::keyboard()
{
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);

    if (keystates[SDL_SCANCODE_UP])
    {
        if(head->GetDir() != DOWN)
        {
            head->SetDir(UP);
        }
    }
    if (keystates[SDL_SCANCODE_DOWN])
    {
        if(head->GetDir() != UP)
        {
            head->SetDir(DOWN);
        }
    }
    if (keystates[SDL_SCANCODE_LEFT])
    {
        if(head->GetDir() != RIGHT)
        {
            head->SetDir(LEFT);
        }
    }
    if (keystates[SDL_SCANCODE_RIGHT])
    {
        if(head->GetDir() != LEFT)
        {
            head->SetDir(RIGHT);
        }
    }
}

void Snake::Move()
{
    Segment* tmp = head;
    while(tmp != NULL){
        switch (tmp->GetDir())
        {

        case UP:
            tmp->SubY();
            break;

        case DOWN:
            tmp->AddY();
            break;

        case LEFT:
            tmp->SubX();
            break;

        case RIGHT:
            tmp->AddX();
            break;
        }
        tmp = tmp->GetNext();
    }
}

int Snake::Collide() {
    if (head->GetX() < 0 || 
        head->GetX() > WIDTH ||
        head->GetY() < 0 ||
        head->GetY() > HEIGHT) {
            return 0;
    }
    else {
        return 1;
    }
}

void Snake::Draw(SDL_Renderer *renderer)
{
    Segment* tmp = head;
    while(tmp != NULL){
        SDL_SetRenderDrawColor(renderer, 65, 22, 247, 255);
        SDL_Rect rect = {tmp->GetX(), tmp->GetY(), SNAKE_SIZE, SNAKE_SIZE};
        SDL_RenderFillRect(renderer, &rect);
        tmp = tmp->GetNext();
    }
}