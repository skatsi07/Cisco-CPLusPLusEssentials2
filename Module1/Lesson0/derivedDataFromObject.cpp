#include <iostream>

class AdHocSquare
{
public:
  AdHocSquare(double side);
  void set_side(double side);
  double get_area();
private:
  double    side;
};

double AdHocSquare::get_area()
{
  return side * side;
}

void AdHocSquare::set_side(double new_side)
{
  this->side = new_side;
}

AdHocSquare::AdHocSquare(double side)
{
  this->side = side;
}



class LazySquare
{
public:
  LazySquare(double side);
  void set_side(double side);
  double get_area();
private:
  double    side;
  double    area;
  bool      side_changed;
};

void LazySquare::set_side(double new_side)
{
  this->side = new_side;
  this->side_changed = true;
}

LazySquare::LazySquare(double side)
{
  this->side = side;
  this->area = side * side;
  this->side_changed = false;
}

double LazySquare::get_area()
{
  if (side_changed)
  {
    area = side * side;
    side_changed = false;
  }
  return area;
}

int main()
{
  AdHocSquare s1(4);
  std::cout << "Square area=" << s1.get_area() << std::endl;

  LazySquare s2(6);
  std::cout << "Square area=" << s2.get_area() << std::endl;

  return 0;
}