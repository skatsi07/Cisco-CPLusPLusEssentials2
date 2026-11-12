#include <iostream>

using namespace std;

class Point2D{
public:
  Point2D(double x, double y);
  string toString();
  double distanceTo(Point2D that);
  double get_x() {return x;}
  double get_y() { return y;}
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

class Line2D{
public:
  Line2D(double slope, double y_intercept);
  Line2D(Point2D pointA, Point2D pointB);
  string toString();
private:
  double slope;
  double y_intercept;
};

Line2D::Line2D(Point2D pointA, Point2D pointB){
    this->slope = (pointB.get_y() - pointA.get_y()) / (pointB.get_x() - pointA.get_x());
    this->y_intercept = pointA.get_y() - this->slope * pointA.get_x();
}

string Line2D::toString(){
    return "y = " + to_string(this->slope) + "x + " + to_string(this->y_intercept);
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

    Line2D line(point1, point2);
    cout << line.toString() << endl;

    return 0;
}