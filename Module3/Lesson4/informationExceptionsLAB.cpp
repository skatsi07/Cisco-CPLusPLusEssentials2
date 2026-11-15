#include <cctype>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class IPHeader {
public:
  IPHeader(const string source, const string destination);

private:
  string sourceIP;
  string destinationIP;

  void checkIP(const string address, const string label);
  void checkPart(const string part, const string label);
};

IPHeader::IPHeader(const string source, const string destination) {
  sourceIP = source;
  destinationIP = destination;

  checkIP(sourceIP, "Source IP Address");
  checkIP(destinationIP, "Destination IP Address");
}

void IPHeader::checkIP(string address, string label){
  if (address.empty() || address[0] == '.' ||
      address[address.length() - 1] == '.') {
    throw invalid_argument(label + " is invalid.");
  }

  string curr = "";
  int partsCount = 0;

  for (int i = 0; i < address.length(); i++) {
    char c = address[i];

    // represents new part
    if (c == '.') {
      if (curr.empty() || partsCount >= 3) {
        throw invalid_argument(label + " is invalid.");
      }
      checkPart(curr, label);
      partsCount++;
      curr = "";
    } else if (isdigit(c)) {
      curr += c;
    } else {
      throw invalid_argument(label + " is invalid.");
    }
  }

  // Check final ip part
  if (curr.empty() || partsCount != 3) {
    throw invalid_argument(label + " is invalid.");
  }
  checkPart(curr, label);
}

void IPHeader::checkPart(string part, string label){
  if (part.length() > 3) {
    throw invalid_argument(label + " is invalid.");
  }
  int value = stoi(part);
  if (value < 0 || value > 255) {
    throw invalid_argument(label + " is invalid.");
  }
}

int main() {
  string sourceIP, destinationIP;

  while (cin >> sourceIP >> destinationIP) {
    try {
      IPHeader header(sourceIP, destinationIP);
      cout << "Valid IP Header." << endl;
    } catch (invalid_argument &ex) {
      cout << "Invalid IP Header - " << ex.what() << endl;
    }
  }

  return 0;
}