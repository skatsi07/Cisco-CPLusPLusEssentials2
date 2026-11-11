#include <iostream>
#include <string>

using namespace std;

class Square
{
public:
  Square(double side);
  double get_area() {return area;}
  double get_side() {return side;}
  void set_side(double new_side);
  private:double    side;
  private:double    area;
};

void Square::set_side(double new_side)
{
  if (new_side >= 0)
  {
    side = new_side;
    area = side * side;
  }
}

Square::Square(double side)
{
  this->side = side;
  this->area = side * side;
}

void print(Square* square)
{
  cout << "Square: side=" << square->get_side() << " area=" << square->get_area() << endl;
}


int main()
{
  Square s(4);


  print(&s);

  s.set_side(2.0);
  print(&s);

  s.set_side(-33.0);
  print(&s);

  return 0;
}