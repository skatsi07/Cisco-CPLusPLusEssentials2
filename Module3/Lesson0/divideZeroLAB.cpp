#include <iostream>
using namespace std;

class DivideByZeroException : public exception {
public:
  const char *what() const throw() {
    return "Your input is not valid, you can't divide by zero.";
  }
};

int main() {
  int numerator, denominator;
  cout << "Enter numerator: ";
  cin >> numerator;
  cout << "Enter denominator: ";
  cin >> denominator;

  try {
    if (denominator == 0) {
      throw DivideByZeroException();
    }
    cout << numerator / denominator << endl;

  } catch (DivideByZeroException &e) {
    cout << e.what() << endl;
  }

  return 0;
}
