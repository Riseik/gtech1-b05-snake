#include <SDL2/SDL.h>

class Playground {
public:
  Playground();
  ~Playground();
  SDL_Renderer *GetRenderer();
  int Init(int nbrow, int nbcol, SDL_Renderer* renderer);
private:
  int nbrow;
  int nbcol;
};