#include <iostream>
#include <string>

using namespace std;

class Fraction{
public:
  Fraction(int numerator, int denominator);
  string toString();
  double toDouble();
private:
  int numerator;
  int denominator;
};

Fraction::Fraction(int numerator, int denominator){
  this->numerator = numerator;
  this->denominator = denominator;
}

string Fraction::toString(){
  return to_string(numerator) + "/" + to_string(denominator);
}

double Fraction::toDouble(){
  return (double)numerator / denominator;
}

int main(void) {
  int num, den;
  string input = "";
  getline(cin, input);

  // get num and den form input like '3/4'
  string numStr = input.substr(0, input.find("/"));
  string denStr = input.substr(input.find("/") + 1);

  num = stoi(numStr);
  den = stoi(denStr);

  Fraction fraction(num, den);
  
  cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal" << endl;
  return 0;
}