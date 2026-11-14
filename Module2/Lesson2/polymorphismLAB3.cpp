#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class IPAddress {
public:
  IPAddress(string ip) : ip(ip) {}
  void printAddressBool();

protected:
  string ip;
};

void IPAddress::printAddressBool() { cout << ip; }

class IPAddressChecked : IPAddress {
private:
  bool correctIP;
  bool checkIP();

public:
  IPAddressChecked(string ip) : IPAddress(ip) { correctIP = checkIP(); }
  void printAddressBool();
};

bool IPAddressChecked::checkIP() {
  stringstream splited(ip);
  string s;
  int partsCount = 0;
  while (std::getline(splited, s, '.')) {
    if (3 < s.length() || s.length() < 1)
      return false;
    if (partsCount > 4)
      return false;
    for (int i = 0; i < s.length(); i++) {
      if (!isdigit(s[i]))
        return false;
    }
    int partValue = atoi(s.c_str());
    if (partValue > 255)
      return false;
    partsCount++;
  }
  if (partsCount != 4)
    return false;
  return true;
}

void IPAddressChecked::printAddressBool() {
  IPAddress::printAddressBool();
  cout << " - " << (correctIP ? "Correct" : "Not Correct") << endl;
}

int main() {
  IPAddressChecked ip3("1.2.3.4");
  ip3.printAddressBool();

  IPAddressChecked ip1("999.29.29.29");
  ip1.printAddressBool();

  IPAddressChecked ip2("199.29.29.29");
  ip2.printAddressBool();

  return 0;
}