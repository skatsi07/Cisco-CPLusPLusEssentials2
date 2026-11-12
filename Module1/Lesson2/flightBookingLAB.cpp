#include <iostream>

using namespace std;

class FlightBooking {
public:
  FlightBooking(int id, int capacity, int reserved);
  void printStatus();
  bool reserveSeats(int number_of_seats);
  bool cancelReservations(int number_of_seats);
  double getPercentageBooked() {return ((double)reserved/capacity) * 100;};
private:
  int id;
  int capacity;
  int reserved;
  double percentageBooked;
};

void FlightBooking::printStatus()
{
  cout << "Flight " << id << " : " << reserved << "/" << capacity << " (" << percentageBooked << "%) seats reserved" << endl;
}

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
  this->id = id;
  this->capacity = capacity;
  this->reserved = reserved;
  this->percentageBooked = getPercentageBooked();

  //check to make sure percenatge booked is not over 105%
  if (percentageBooked > 105){
    reserved = capacity * 1.05;
    this -> percentageBooked = 105;
  }
}

bool FlightBooking::reserveSeats(int number_of_seats)
{
  // try to add reservations and return 'true' on success
  // keep the limits in mind
  
  if ((reserved + number_of_seats)*100 > (capacity*105)){
    cout << "Cannot perform this operation";
    return false;
  }

  this -> reserved += number_of_seats;
  return true;
}

bool FlightBooking::cancelReservations(int number_of_seats)
{
  // try to cancel reservations and return 'true' on success
  // keep the limits in mind
  if (number_of_seats > reserved){
    cout << "Cannot perform this operation" << endl;
    return false;
  }
  this -> reserved -= number_of_seats;
  return true;
}

int main() {
  int reserved = 0,
      capacity = 0;
  std::cout << "Provide flight capacity: ";
  std::cin >> capacity;

  std::cout << "Provide number of reserved seats: ";
  std::cin >> reserved;

  FlightBooking booking(1, capacity, reserved);

  std::string command = "";
  while (command != "quit")
  {
    booking.printStatus();
    std::cout << "What would you like to do?: ";
    std::getline(cin, command);

    // if "add [n]" add n reservations to flight
    if (command.find("add") == 0)
    {
      int number_of_seats = stoi(command.substr(4));
      booking.reserveSeats(number_of_seats);
    }

    // if "cancel [n]" cancel n reservations from flight
    else if (command.find("cancel") == 0)
    {
      int number_of_seats = stoi(command.substr(7));
      booking.cancelReservations(number_of_seats);
    }

    // if "quit" exit the program
    else if (command == "quit")
    {
      break;
    }
  }

  return 0;
}