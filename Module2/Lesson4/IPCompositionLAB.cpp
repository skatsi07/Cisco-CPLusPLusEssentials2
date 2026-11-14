#include <iostream>
#include <string>

using namespace std;

// ip address object to store a single IP address
class IPAddress {
public:
  IPAddress() : address("") {}
  IPAddress(const string address) : address(address) {}

  string getAddress();
  void setAddress(string address);
  void print();

private:
  string address;
};

string IPAddress ::getAddress() { return address; }

void IPAddress ::setAddress(string address) { this->address = address; }

void IPAddress ::print() { cout << address << endl; }


//store a bunch of IP addresses
class Network {
public:
  Network(const string &name) : name(name), addressCount(0) {}
  void addAddress(IPAddress address);
  void print();

private:
  string name;
  int addressCount;
  IPAddress addresses[100];
};

void Network :: print() {
    cout << name << ":" << endl;
    for (int i = 0; i < addressCount; i++)
      addresses[i].print();
}

void Network :: addAddress(IPAddress address){
    addresses[addressCount] = address;
    addressCount++;
}

int main() {
  Network network1("Network 1");
  Network network2("Network 2");

  IPAddress ip1("1.1.1.1");
  IPAddress ip2("2.2.2.2");
  IPAddress ip3("3.3.3.3");
  IPAddress ip4("4.4.4.4");
  IPAddress ip5("5.5.5.5");

  network1.addAddress(ip1);
  network1.addAddress(ip2);
  network1.addAddress(ip3);

  network2.addAddress(ip3);
  network2.addAddress(ip4);
  network2.addAddress(ip5);

  cout << endl;
  network1.print();
  cout << endl;
  network2.print();

  return 0;
}