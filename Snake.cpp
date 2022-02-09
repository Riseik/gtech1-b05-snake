#include "Snake.hpp"

Segment::Segment(int x, int y, Direction dir, Segment *next)
{
    this->x = x;
    this->y = y;
    this->dir = dir;
    this->next = next;
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
    return x += 20;
}

int Segment::AddY()
{
    return y += 20;
}

int Segment::RemX()
{
    return x -= 20;
}

int Segment::RemY()
{
    return y -= 20;
}

Snake::Snake(int x, int y, Direction dir)
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
        head->SetDir(UP);
        printf("1\n");
    }
    if (keystates[SDL_SCANCODE_DOWN])
    {
        head->SetDir(DOWN);
    }
    if (keystates[SDL_SCANCODE_LEFT])
    {
        head->SetDir(LEFT);
    }
    if (keystates[SDL_SCANCODE_RIGHT])
    {
        head->SetDir(RIGHT);
    }
}

void Snake::Move()
{
    switch (head->GetDir())
    {

    case UP:
        head->RemY();
        break;

    case DOWN:
        head->AddY();
        break;

    case LEFT:
        head->RemX();
        break;

    case RIGHT:
        head->AddX();
        break;
    }
}

void Snake::Draw(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 200, 100, 255);
    SDL_Rect rect = {this->head->GetX(), this->head->GetY(), SNAKE_SIZE, SNAKE_SIZE};
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderPresent(renderer);
}