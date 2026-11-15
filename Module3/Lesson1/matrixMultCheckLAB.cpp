#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix {
public:
  // create matrix with specific size
  Matrix(int r, int c) {
    if (r <= 0 || c <= 0) {
      throw invalid_argument("Matrix dimensions must be greater than zero.");
    }
    rows = r;
    cols = c;
    data = vector<vector<double>>(rows, vector<double>(cols, 0.0));
  }

  void fill(double value);
  void addValue(double value);
  Matrix addMatrix(const Matrix &other);
  void print();

private:
  int rows;
  int cols;
  vector<vector<double>> data;
};

void Matrix::fill(double value) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      data[i][j] += value;
    }
  }
}

void Matrix ::addValue(double value) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      data[i][j] += value;
    }
  }
}

void Matrix ::print() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << data[i][j] << " ";
    }
    cout << endl;
  }
}

Matrix Matrix ::addMatrix(const Matrix &other) {
  if (rows != other.rows || cols != other.cols) {
    throw invalid_argument("Matrices do not have the same dimensions.");
  }

  Matrix result(rows, cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result.data[i][j] = data[i][j] + other.data[i][j];
    }
  }
  return result;
}

int main() {
  // three testing matrices
  Matrix m1(2, 2);
  Matrix m2(2, 2);
  Matrix m3(3, 3);

  m1.fill(2);
  m2.fill(3);
  m2.addValue(1);
  m3.fill(5);

  // m1 + m2 (valid: both 2x2)
  try {
    cout << "m1 + m2:" << endl;
    Matrix sum12 = m1.addMatrix(m2);
    sum12.print();
  } catch (exception &e) {
    cout << "Error: " << e.what() << endl;
  }

  cout << endl;

  // m1 + m3 (invalid: 2x2 vs 3x3)
  try {
    cout << "m1 + m3:" << endl;
    Matrix sum13 = m1.addMatrix(m3);
    sum13.print();
  } catch (exception &e) {
    cout << "Error: " << e.what() << endl;
  }

  cout << endl;

  // m2 + m3 (invalid: 2x2 vs 3x3)
  try {
    cout << "m2 + m3:" << endl;
    Matrix sum23 = m2.addMatrix(m3);
    sum23.print();
  } catch (exception &e) {
    cout << "Error: " << e.what() << endl;
  }

  return 0;
}