#include <iostream>
using namespace std;
const int DivideByZero = 357;
int main(void) {
  int a = 8, b = 0, c = 0;
  cin >> b;
  try {
    if (b == 0) {
      throw DivideByZero;
    }
    c = a / b;
  } catch (int problem) {
    if (problem == DivideByZero) {
      cout << "Cannot divide by zero!" << endl;
    }
  }
  cout << c << endl;
  return 0;
}