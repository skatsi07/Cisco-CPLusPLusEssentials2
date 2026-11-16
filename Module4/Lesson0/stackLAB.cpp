#include <iostream>
#include <stdexcept>

using namespace std;

class Stack {
public:
  Stack(int size = 100) {
    topInd = -1;
    maxSize = size;
    stackArray = new int[maxSize];
  }

  ~Stack() { delete[] stackArray; }

  void push(int value) {
    if (isFull()) {
      throw runtime_error("Stack is full");
    }
    topInd++;
    stackArray[topInd] = value;
  }

  int pop() {
    if (isEmpty()) {
      throw runtime_error("Stack is empty");
    }
    int value = stackArray[topInd];
    topInd--;
    return value;
  }

  bool isEmpty() { return topInd == -1; }

  bool isFull() { return topInd == maxSize - 1; }

  //for push
  friend Stack &operator<<(Stack &s, int value) {
    s.push(value);
    return s;
  }

  //for pop
  friend Stack &operator>>(Stack &s, int &value) {
    value = s.pop();
    return s;
  }

private:
  int *stackArray;
  int topInd;
  int maxSize;
};

int main() {
  int pushCount;
  cout << "How many items should be pushed onto the stack? ";
  cin >> pushCount;

  Stack myStack(pushCount > 0 ? pushCount : 1);

  try {
    for (int i = 0; i < pushCount; i++) {
      int val;
      cout << "Enter item " << (i + 1) << ": ";
      cin >> val;
      myStack << val;
    }

    int popCount;
    cout << "How many items should be printed and popped from the stack? ";
    cin >> popCount;

    for (int i = 0; i < popCount; i++) {
      int poppedVal;
      myStack >> poppedVal;
      cout << poppedVal << endl;
    }
  } catch (exception &e) {
    cout << "Exception: " << e.what() << endl;
  }

  return 0;
}