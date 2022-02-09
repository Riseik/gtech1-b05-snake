#include "Fruits.hpp"

Fruits::Fruits(int x, int y) {
    this->x = x;
    this->y = y;
}

Fruits::~Fruits() {

}

int Fruits::GetX() {
    return x;
}

int Fruits::GetY() {
    return y;
}