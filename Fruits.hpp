#include <SDL2/SDL.h>

class Fruits{
public:
  Fruits();
  ~Fruits();
  int GetX();
  int GetY();
  int RandX();
  int RandY();
  void Draw(SDL_Renderer *renderer);
private:
  SDL_Renderer *renderer;
  int xf;
  int yf;
};