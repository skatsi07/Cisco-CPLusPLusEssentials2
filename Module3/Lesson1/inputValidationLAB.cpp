#include <iostream>

using namespace std;
const int DivideByZero = 111;
using namespace std;
float internaldiv(float arg1, float arg2) {
  if (0 == arg2)
    throw DivideByZero;
  return arg1 / arg2;
}

void div(float &res, float arg1, float arg2) { res = internaldiv(arg1, arg2); }

int main(void) {
  float r, a, b;
  while (cin >> a) {
    cin >> b;
    try {
      div(r, a, b);
      cout << r << endl;
    } catch (int e) {
      cout << "Cannot divide by zero!" << endl;
    }
    cout << r << endl;
  }
  return 0;
}