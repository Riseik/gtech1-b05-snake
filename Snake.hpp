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
  void SetNext(Segment* next);
  int GetX();
  int GetY();
  int AddX();
  int AddY();
  int SubX();
  int SubY();
private:
  Direction dir;
  Segment *next;
  int x;
  int y;
};

class Snake {
public:
  Snake(int x, int y, Direction dir, int lenght);
  ~Snake();
  Segment* GetHead();
  void keyboard();
  void Move();
  int Collide();
  void Eat();
  void Draw(SDL_Renderer* renderer);
private:
  Segment* head;
  int x;
  int y;
  int dir;
  int lenght;
};