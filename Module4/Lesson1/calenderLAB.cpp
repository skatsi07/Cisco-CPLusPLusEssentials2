#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class Day {
public:
  enum weekday { MON = 1, TUE, WED, THU, FRI, SAT, SUN };

  Day(int n) {
    if (n < 1 || n > 7) {
      throw invalid_argument("Invalid day");
    }
    day = weekday(n);
  }

  weekday dayCheck();
  void printDay();

private:
  weekday day;
};

Day::weekday Day::dayCheck() { return day; }

void Day::printDay() {
  const string days[] = {"",         "Monday", "Tuesday",  "Wednesday",
                         "Thursday", "Friday", "Saturday", "Sunday"};
  cout << days[day];
}

class Month {
public:
  enum monthName {
    JAN = 1,
    FEB,
    MAR,
    APR,
    MAY,
    JUN,
    JUL,
    AUG,
    SEP,
    OCT,
    NOV,
    DEC
  };

  Month(int n) {
    if (n < 1 || n > 12) {
      throw invalid_argument("Invalid month");
    }
    month = monthName(n);
  }

  monthName monthCheck();
  void printMonth();

private:
  monthName month;
};

Month::monthName Month::monthCheck() { return month; }

void Month::printMonth() {
  const string months[] = {
      "",     "January", "February",  "March",   "April",    "May",     "June",
      "July", "August",  "September", "October", "November", "December"};
  cout << months[month];
}

class Calendar {
public:
  Calendar(int d_in, int m, int y) : month(m), day(1), date(d_in), year(y) {
    if (y < 1970) {
      throw invalid_argument("Date cannot be earlier than 1st January 1970");
    }
    if (d_in < 1 || d_in > daysInMonth(m, y)) {
      throw invalid_argument("Invalid day for the given month/year");
    }

    daysSince1970 = calculateDaysSince1970(d_in, m, y);
    int dow = findDayOfTheWeek(daysSince1970);
    day = Day(dow);
  }

  void printCalender();

private:
  bool isLeapYear(int y);
  int daysInMonth(int m, int y);
  int calculateDaysSince1970(int d, int m, int y);
  int findDayOfTheWeek(int totalDays);

  Month month;
  Day day;
  int date;
  int year;
  int daysSince1970;
};

bool Calendar::isLeapYear(int y) {
  return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int Calendar::daysInMonth(int m, int y) {
  int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (m == 2 && isLeapYear(y)) {
    return 29;
  }
  return days[m];
}

int Calendar::calculateDaysSince1970(int d, int m, int y) {
  int totalDays = 0;

  // add days for full years since 1970
  for (int i = 1970; i < y; i++) {
    totalDays += isLeapYear(i) ? 366 : 365;
  }

  // add days for full months in the current year
  for (int i = 1; i < m; i++) {
    totalDays += daysInMonth(i, y);
  }

  // add remaining days in the current month (subtract 1 because Jan 1 is day 0)
  totalDays += (d - 1);

  return totalDays;
}

int Calendar::findDayOfTheWeek(int totalDays) {
  int rem = totalDays % 7;
  int dow = (rem + 4);
  if (dow > 7) {
    dow -= 7;
  }
  return dow;
}

void Calendar::printCalender() {
  cout << date << " ";
  month.printMonth();
  cout << " " << year << " - ";
  day.printDay();
  cout << " - " << daysSince1970 << " days since 1st January 1970" << endl;
}

int main() {
  int d, m, y;
  cout << "Enter day, month, and year (e.g., 13 3 2016): ";

  if (cin >> d >> m >> y) {
    try {
      Calendar cal(d, m, y);
      cal.printCalender();
    } catch (const exception &e) {
      cout << "Error: " << e.what() << endl;
    }
  }

  return 0;
}