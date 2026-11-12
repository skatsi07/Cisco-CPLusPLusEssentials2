#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class GymMember {
public:
  GymMember(int id = 0, string name = "", int months = 0);
  void printStatus() const;
  bool extendSubscription(int n);
  bool cancelSubscription();
  int getId() const { return id; }

private:
  int id;
  string name;
  int months;
};

GymMember::GymMember(int id, string name, int months) {
  this->id = id;
  this->name = name;
  this->months = months;
}

void GymMember::printStatus() const {
  if (id != 0) {
    cout << "Member " << id << " : " << name << ", subscription valid for "
         << months << " months" << endl;
  }
}

// extend subscriptions
bool GymMember::extendSubscription(int n) {
  if (n <= 0) {
    return false;
  }
  months += n;
  return true;
}

// cancel subscriptions
bool GymMember::cancelSubscription() {
  if (months == 0) {
    return false;
  }
  months = 0;
  return true;
}

const int MAX_MEMBERS = 10;

int main() {
  GymMember members[MAX_MEMBERS];
  string line = "";

  while (true) {
    bool any_member_valid = false;

    // show all members and their status
    for (int idx = 0; idx < MAX_MEMBERS; ++idx) {
      if (members[idx].getId() != 0) {
        any_member_valid = true;
      }
      members[idx].printStatus();
    }
    if (!any_member_valid) {
      cout << "No members in the system" << endl;
    }

    // get command from user
    cout << "What would you like to do?: ";
    line = "";
    while (line.empty()) {
      if (!getline(cin, line)) {
        return 0;
      }
    }

    stringstream ss(line);
    string command;
    ss >> command;

    if (command == "quit") {
      break;
    }

    bool command_known = false;
    bool command_ok = false;
    string error = "";

    if (command == "create") {
      command_known = true;
      int id = 0;
      string name;

      // Read ID, strip leading whitespace, then read the full rest of the line
      // as name
      // used some AI to get the whitespace strip + previous labs
      if (ss >> id && getline(ss >> ws, name) && !name.empty() && id > 0) {
        bool exists = false;
        // check to make sure unique id
        for (int i = 0; i < MAX_MEMBERS; ++i) {
          if (members[i].getId() == id) {
            exists = true;
            break;
          }
        }

        if (exists) {
          error = "member " + to_string(id) + " already exists";
        } else {
          // Find first empty slot (id == 0)
          int idx = 0;
          while (idx < MAX_MEMBERS && members[idx].getId() != 0) {
            idx++;
          }

          // check if max members
          if (idx < MAX_MEMBERS) {
            members[idx] = GymMember(id, name, 0);
            command_ok = true;
          } else {
            error = "maximum member limit reached";
          }
        }
      } else {
        error = "invalid arguments for create (expected: create [id] [name])";
      }
    } else if (command == "delete") {
      command_known = true;
      int id = 0;

      //make sure id is valid and then delete
      if (ss >> id && id > 0) {
        int idx = 0;
        while (idx < MAX_MEMBERS && members[idx].getId() != id) {
          idx++;
        }

        if (idx < MAX_MEMBERS) {
          members[idx] = GymMember();
          command_ok = true;
        } else {
          error = "member " + to_string(id) + " not found";
        }
      } else {
        error = "invalid member id";
      }
    } else if (command == "extend") {
      command_known = true;
      int id = 0;
      int months = 0;

      //make sure id is valid then extend
      if (ss >> id && ss >> months && id > 0) {
        int idx = 0;
        while (idx < MAX_MEMBERS && members[idx].getId() != id) {
          idx++;
        }

        if (idx < MAX_MEMBERS) {
          command_ok = members[idx].extendSubscription(months);
          if (!command_ok) {
            error = "months to extend must be greater than 0";
          }
        } else {
          error = "member " + to_string(id) + " not found";
        }
      } else {
        error = "invalid arguments for extend (expected: extend [id] [n])";
      }

    //make sure id is valid then cancel
    } else if (command == "cancel") {
      command_known = true;
      int id = 0;

      if (ss >> id && id > 0) {
        int idx = 0;
        while (idx < MAX_MEMBERS && members[idx].getId() != id) {
          idx++;
        }

        if (idx < MAX_MEMBERS) {
          command_ok = members[idx].cancelSubscription();
          if (!command_ok) {
            error = "subscription already has 0 months";
          }
        } else {
          error = "member " + to_string(id) + " not found";
        }
      } else {
        error = "invalid member id";
      }
    }

    if (command_known && !command_ok) {
      cout << "Cannot perform this operation: " << error << endl;
    } else if (!command_known) {
      cout << "Unknown command" << endl;
    }
  }

  return 0;
}