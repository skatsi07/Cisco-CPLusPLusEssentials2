#include <iostream>
#include <ostream>

using namespace std;

class Matrix {
public:
  Matrix(int rows, int cols);

  Matrix add(const Matrix &other) const;
  Matrix addToAll(int num) const;
  Matrix substract(const Matrix &other) const;
  Matrix subtractFromAll(int num) const;
  Matrix multiply(const Matrix &other) const;
  Matrix multiplyByNum(int num) const;
  void print() const;

private:
  int rows;
  int cols;
  int **data;
};

Matrix::Matrix(int rows, int cols) {
  this->rows = rows;
  this->cols = cols;
  data = new int *[rows];
  for (int i = 0; i < rows; i++) {
    data[i] = new int[cols];
    for (int j = 0; j < cols; j++) {
      data[i][j] = 0;
    }
  }
}

Matrix Matrix::add(const Matrix &other) const {
  Matrix result(rows, cols);
  if (rows != other.rows || cols != other.cols) {
    cout << "Dimensions are not the same" << endl;
    return result;
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result.data[i][j] = data[i][j] + other.data[i][j];
    }
  }
  return result;
}

Matrix Matrix::addToAll(int num) const {
  Matrix result(rows, cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result.data[i][j] = data[i][j] + num;
    }
  }
  return result;
}

Matrix Matrix::substract(const Matrix &other) const {
  if (rows != other.rows || cols != other.cols) {
    cout << "Dimensions are not the same" << endl;
    return Matrix(rows, cols);
  }
  Matrix result(rows, cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result.data[i][j] = data[i][j] - other.data[i][j];
    }
  }
  return result;
}

Matrix Matrix::subtractFromAll(int num) const {
  Matrix result(rows, cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result.data[i][j] = data[i][j] - num;
    }
  }
  return result;
}

Matrix Matrix::multiply(const Matrix &other) const {
  if (cols != other.rows) {
    cout << "Dimensions are not compatible for multiplication" << endl;
    return Matrix(rows, other.cols);
  }

  //algorithm help from Gemini
  Matrix result(rows, other.cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < other.cols; j++) {
      result.data[i][j] = 0;
      for (int k = 0; k < cols; k++) {
        result.data[i][j] += data[i][k] * other.data[k][j];
      }
    }
  }
  return result;
}

Matrix Matrix::multiplyByNum(int num) const {
  Matrix result(rows, cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result.data[i][j] = data[i][j] * num;
    }
  }
  return result;
}

Matrix operator*(const Matrix &a, const Matrix &b) { return a.multiply(b); }

Matrix operator+(const Matrix &a, const Matrix &b) { return a.add(b); }

Matrix operator-(const Matrix &a, const Matrix &b) { return a.substract(b); }

Matrix operator*(const Matrix &a, int num) { return a.multiplyByNum(num); }

Matrix operator+(const Matrix &a, int num) { return a.addToAll(num); }

Matrix operator-(const Matrix &a, int num) { return a.subtractFromAll(num); }

void Matrix::print() const {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << data[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  Matrix m1(2, 2);
  Matrix m2(2, 2);
  Matrix m3(2, 3);

  // Add 1 to all cells in m1
  m1 = m1 + 1;

  // Add 3 to all cells in m2
  m2 = m2 + 3;

  // Add 2 to all cells in m3
  m3 = m3 + 2;

  cout << "m1:" << endl;
  m1.print();

  cout << "\nm2:" << endl;
  m2.print();

  cout << "\nm1 + m2:" << endl;
  Matrix m4 = m1 + m2;
  m4.print();

  cout << "\nm1 * m3 (2x2 * 2x3):" << endl;
  Matrix m5 = m1 * m3;
  m5.print();

  // try invalid m3*m1
  Matrix m6 = m3 * m1;
  m6.print();

  return 0;
}