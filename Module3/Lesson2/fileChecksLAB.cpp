#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class Matrix {
public:
  // fills the 2x2 matrix with 0s
  Matrix() {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        data[i][j] = 0.0;
      }
    }
  }

  // read 4 numbers from user input
  void inputFromUser() {
    double inp;
    cout << "Enter 4 numbers for the 2x2 matrix:" << endl;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        if (!(cin >> inp)) {
          // using runtime error here as it is the base class for exceptions
          throw runtime_error("Invalid number entered.");
        }
        data[i][j] = inp;
      }
    }
  }

  // Save the 2x2 matrix to a file
  void saveToFile(const string &filename) {
    try {
      ofstream file(filename);
      if (!file.is_open()) {
        throw runtime_error(
            "Cannot open file for writing (no rights or invalid path): " +
            filename);
      }

      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
          file << data[i][j] << " ";
        }
        file << endl;
      }
      file.close();
    } catch (exception &e) {
      cout << "[Inside saveToFile] Error: " << e.what() << endl;
      throw;
    }
  }

  // load the 2x2 matrix from a file
  // used help of Google gemini for this
  void loadFromFile(const string &filename) {
    try {
      ifstream file(filename);
      if (!file.is_open()) {
        throw runtime_error("File not found or cannot be opened: " + filename);
      }

      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
          if (!(file >> data[i][j])) {
            throw runtime_error("Error reading matrix values from file: " +
                                filename);
          }
        }
      }
      file.close();
    } catch (exception &e) {
      cout << "[Inside loadFromFile] Error: " << e.what() << endl;
      throw;
    }
  }

  // print the 2x2 matrix
  void print() {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        cout << data[i][j] << " ";
      }
      cout << endl;
    }
  }

private:
  double data[2][2];
};

int main() {
  Matrix m;

  // save and load
  try {
    m.inputFromUser();
    cout << "Matrix saved successfully to matrix.txt" << endl;

    Matrix mLoaded;
    mLoaded.loadFromFile("matrix.txt");
    cout << "Loaded matrix:" << endl;
    mLoaded.print();
  } catch (exception &e) {
    cout << "[Main] Caught exception: " << e.what() << endl;
  }

  cout << "\n--- Simulating Exceptions ---" << endl;

  // Simulate loading a nonexistent file
  // used Gemini help for what it meant here
  try {
    m.loadFromFile("does_not_exist.txt");
  } catch (exception &e) {
    cout << "[Main] Caught re-thrown load exception: " << e.what() << endl;
  }

  cout << endl;

  // Simulate saving to a path without permission
  // /root/ is a folder in linux that is not allowed to be written to for
  // regular users used Gemini help for what it meant here
  try {
    m.saveToFile("/root/matrix.txt");
  } catch (exception &e) {
    cout << "[Main] Caught re-thrown save exception: " << e.what() << endl;
  }

  return 0;
}