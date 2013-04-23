#import "rect.hpp"

Rectangle::Rectangle() {
  x = 200;
  y = 4000;
  width = 100;
  length = 50;
}

int Rectangle::getX() {
  return x;
}

void Rectangle::setPosition(int x, int y) {
  this->x = x;
  this->y = y;
}

ostream &operator << (ostream& out, Rectangle* st) {
  if (st == NULL) {
    out << "Rectangle: NULL";
  } else {
    out << "Rectangle: " << st->x << ", " << st->y
	<< " [" << st->width << " x " << st->length << "]";
  }
  return out;
}
