#import "rect.hpp"

Rectangle::Rectangle() {
  x = 50;
  y = 100;
}

ostream &operator << (ostream& out, Rectangle* st) {
  if (st == NULL) {
    out << "Rectangle: NULL";
  } else {
    out << "Rectangle: " << st->x << ", " << st->y;
  }
  return out;
}
