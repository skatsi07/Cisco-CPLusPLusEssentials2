#include <iostream>
#include <string>

using namespace std;

class Fraction {
public:
  Fraction(int numerator, int denominator);
  string toString();
  double toDouble();
  // the functions below do not change the object
  // on which they are called, they produce a new object
  Fraction plus(Fraction that);
  Fraction minus(Fraction that);
  Fraction times(Fraction that);
  Fraction by(Fraction that);

  bool isGreaterThan(Fraction that);
  bool isLessThan(Fraction that);
  bool isEqual(Fraction that);

private:
  int numerator;
  int denominator;
  void reduce();
};

Fraction Fraction::times(Fraction that) {
  int num = this->numerator * that.denominator;
  int den = this->denominator * that.denominator;
  Fraction result(num, den);
  result.reduce();
  return result;
}

Fraction Fraction::minus(Fraction that) {
  int num =
      this->numerator * that.denominator - that.numerator * this->denominator;
  int den = this->denominator * that.denominator;
  Fraction result(num, den);
  result.reduce();
  return result;
}

Fraction Fraction::plus(Fraction that) {
  int num =
      this->numerator * that.denominator + that.numerator * this->denominator;
  int den = this->denominator * that.denominator;
  Fraction result(num, den);
  result.reduce();
  return result;
}

Fraction Fraction::by(Fraction that) {
  int num = this->numerator * that.denominator;
  int den = this->denominator * that.numerator;
  Fraction result(num, den);
  result.reduce();
  return result;
}

void Fraction::reduce() {
  int gcd = this->numerator;
  int gcd2 = this->denominator;
  while (gcd2 != 0) {
    int temp = gcd2;
    gcd2 = gcd % gcd2;
    gcd = temp;
  }
  this->numerator /= gcd;
  this->denominator /= gcd;
}

Fraction::Fraction(int numerator, int denominator) {
  this->numerator = numerator;
  this->denominator = denominator;
}

string Fraction::toString() {
  // convert to mixed fraction
  if (abs(this->numerator) >= this->denominator) {
    int wholeNumber = this->numerator / this->denominator;
    int remainder = this->numerator % this->denominator;
    return to_string(wholeNumber) + " " + to_string(remainder) + "/" +
           to_string(this->denominator);
  }
  return to_string(numerator) + "/" + to_string(denominator);
}

double Fraction::toDouble() { return (double)numerator / denominator; }

bool Fraction::isGreaterThan(Fraction that) {
    reduce();
    that.reduce();
    return this->toDouble() > that.toDouble();
}

bool Fraction::isLessThan(Fraction that) {
    reduce();
    that.reduce();
    return this->toDouble() < that.toDouble();
}

bool Fraction::isEqual(Fraction that) {
    reduce();
    that.reduce();
    return this->toDouble() == that.toDouble();
}

int main(void) {

  // get first fraction
  int num1, den1;
  string input1 = "";
  getline(cin, input1);

  // get num and den form input like '3/4'
  string numStr1 = input1.substr(0, input1.find("/"));
  string denStr1 = input1.substr(input1.find("/") + 1);

  num1 = stoi(numStr1);
  den1 = stoi(denStr1);

  Fraction fraction1(num1, den1);

  // get second fraction
  int num2, den2;
  string input2 = "";
  getline(cin, input2);

  // get num and den form input like '3/4'
  string numStr2 = input2.substr(0, input2.find("/"));
  string denStr2 = input2.substr(input2.find("/") + 1);

  num2 = stoi(numStr2);
  den2 = stoi(denStr2);

  Fraction fraction2(num2, den2);

  // print results
  if (fraction1.isGreaterThan(fraction2))
  {
    cout << fraction1.toString() << " > " << fraction2.toString() << endl;
  }
  if (fraction1.isLessThan(fraction2))
  {
    cout << fraction1.toString() << " < " << fraction2.toString() << endl;
  }
  if (fraction1.isEqual(fraction2))
  {
    cout << fraction1.toString() << " = " << fraction2.toString() << endl;
  }

	return 0;
}