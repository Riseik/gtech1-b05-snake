#include <SDL2/SDL.h>

class Fruits{
public:
  Fruits(int x, int y);
  ~Fruits();
  int GetX();
  int GetY();
private:
  int x;
  int y;
}