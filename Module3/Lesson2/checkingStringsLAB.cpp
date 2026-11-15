#include <cctype>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class IPAddress {
public:
  IPAddress(string address) {
    //check doesnt start or end with a dot
    if (address.empty() || address[0] == '.' ||
        address[address.length() - 1] == '.') {
      throw invalid_argument("invalid IP number");
    }

    string curr = "";
    int ind = 0;

    // loop through every char one by one
    for (int i = 0; i < address.length(); i++) {
      char c = address[i];

      if (c == '.') {
        // make sure no empty char or too many parts
        if (curr.empty() || ind >= 3) {
          throw invalid_argument("invalid IP number");
        }
        parts[ind] = convertAndCheckPart(curr);
        ind++;
        curr = "";
      } else if (isdigit(c)) {
        curr += c;
      } else {
        throw invalid_argument("invalid IP number");
      }
    }

    // save 4th part
    if (curr.empty() || ind != 3) {
      throw invalid_argument("invalid IP number.");
    }
    parts[3] = convertAndCheckPart(curr);
  }

  // takes an integer range (1, 2, 4, 8, 16, 32, 64, 128, 256)
  void printRange(int range) {
    // check if range is a valid power of 2
    if (!isValidRange(range)) {
      throw invalid_argument("invalid range.");
    }

    // check if adding the range goes past 255
    if (parts[3] + range > 255) {
      throw invalid_argument("invalid range.");
    }

    // print the subnet IPs
    for (int i = 1; i <= range; i++) {
      cout << parts[0] << "." << parts[1] << "." << parts[2] << "."
           << (parts[3] + i) << endl;
    }
  }

private:
  int parts[4];

  // turn string into int
  int convertAndCheckPart(string part) {
    if (part.length() > 3) {
      throw invalid_argument("invalid IP number.");
    }
    int value = stoi(part);
    if (value < 0 || value > 255) {
      throw invalid_argument("invalid IP number.");
    }
    return value;
  }

  // loop to check if range is power of 2
  // made with the help of gemini
  bool isValidRange(int range) {
    int validValues[9] = {1, 2, 4, 8, 16, 32, 64, 128, 256};
    for (int i = 0; i < 9; i++) {
      if (range == validValues[i]) {
        return true;
      }
    }
    return false;
  }
};

int main() {
  string inputIP;
  int inputRange;

  // loop to test all your sample data easily
  //made with the help of Gemini
  while (cin >> inputIP >> inputRange) {
    try {
      IPAddress ip(inputIP);
      ip.printRange(inputRange);
    } catch (invalid_argument &ex) {
      cout << "Exception - " << ex.what() << endl;
    }
    cout << endl;
  }

  return 0;
}