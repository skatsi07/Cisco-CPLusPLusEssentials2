#include <iostream>

using namespace std;

class Point2D{
public:
  Point2D(double x, double y);
  string toString();
  double distanceTo(Point2D that);
private:
  double x;
  double y;
};

//calculating distance between two points using Pythagorean theorem
double Point2D::distanceTo(Point2D that){
    return sqrt(pow(this->x - that.x, 2) + pow(this->y - that.y, 2));
}

Point2D::Point2D(double x, double y){
    this->x = x;
    this->y = y;
}

string Point2D::toString(){
    return "(" + to_string(this->x) + ", " + to_string(this->y) + ")";
}


int main(void){
    //get first point
    string input1 = "";
    getline(cin, input1);
    double x1, y1;
    sscanf(input1.c_str(), "%lf %lf", &x1, &y1);
    Point2D point1(x1, y1);

    //get second point
    string input2 = "";
    getline(cin, input2);
    double x2, y2;
    sscanf(input2.c_str(), "%lf %lf", &x2, &y2);
    Point2D point2(x2, y2);

    //print distance
    cout << point1.toString() << " - " << point2.toString() << " = " << point1.distanceTo(point2) << endl;

    return 0;
}