#include <iostream>

using namespace std;

class Matrix {
public:
  Matrix(int v1, int v2, int v3, int v4) {
    rows = 2;
    cols = 2;

    data = new int *[rows];
    for (int i = 0; i < rows; i++) {
      data[i] = new int[cols];
    }

    data[0][0] = v1;
    data[0][1] = v2;
    data[1][0] = v3;
    data[1][1] = v4;
  }

  ~Matrix() {
    for (int i = 0; i < rows; i++) {
      delete[] data[i]; 
    }
    delete[] data;
  }

  friend ostream &operator<<(ostream &os, const Matrix &matrix) {
    for (int i = 0; i < matrix.rows; i++) {
      for (int j = 0; j < matrix.cols; j++) {
        os << matrix.data[i][j] << " ";
      }
      os << endl;
    }
    return os;
  }

private:
  int **data;
  int rows;
  int cols;
};

int main() {
  int val1, val2, val3, val4;
  cout << "Enter the values for the matrix: ";
  cin >> val1 >> val2 >> val3 >> val4;

  Matrix matrix(val1, val2, val3, val4);

  cout << matrix;

  return 0;
}