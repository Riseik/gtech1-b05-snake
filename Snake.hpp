#include <SDL2/SDL.h>

typedef enum { 
    UP, DOWN, LEFT, RIGHT
} Direction;

class Segment {
public:
  Segment(int x, int y, Direction dir, Segment* next);
  ~Segment();
  void SetDir(Direction dir);
  Direction GetDir();
  Segment* GetNext();
  int GetX();
  int GetY();
  int AddX();
  int AddY();
  int RemX();
  int RemY();
private:
  Direction dir;
  Segment *next;
  int x;
  int y;
};

class Snake {
public:
  Snake(int x, int y, Direction dir);
  ~Snake();
  Segment* GetHead();
  void keyboard();
  void Move();
  void Draw(SDL_Renderer* renderer);
  int Collide();
private:
  Segment* head;
  Segment* tail;
  int x;
  int y;
  int dir;
  int dirprev;
};