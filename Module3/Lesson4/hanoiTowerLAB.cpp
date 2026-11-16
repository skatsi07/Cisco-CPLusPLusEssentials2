#include <iostream>
#include <stdexcept>

using namespace std;

class InvalidTowerException : public runtime_error {
public:
  InvalidTowerException()
      : runtime_error("Tower number must be between 1 and 3.") {}
};

class InvalidDiskPlacementException : public runtime_error {
public:
  InvalidDiskPlacementException()
      : runtime_error("Cannot place a larger disk on top of a smaller disk.") {}
};

class EmptySourceException : public runtime_error {
public:
  EmptySourceException() : runtime_error("Source tower is empty.") {}
};

class HanoiTower {
public:
  HanoiTower();
  void moveDisk(int command);
  void print();

private:
  int towers[3][3];
  int counts[3];
};

// constructor puts disks 3, 2, 1 on tower_1 (bottom to top)
HanoiTower::HanoiTower() {
  towers[0][0] = 3;
  towers[0][1] = 2;
  towers[0][2] = 1;
  counts[0] = 3;

  counts[1] = 0;
  counts[2] = 0;
}

void HanoiTower::moveDisk(int command) {
  int from = command / 10;
  int to = command % 10;

  // checks to make sure valid command
  if (command < 11 || command > 99 || from < 1 || from > 3 || to < 1 ||
      to > 3) {
    throw InvalidTowerException();
  }

  // rule that moves 11, 22, 33 are valid empty moves
  if (from == to) {
    return;
  }

  // convert tower numbers to array index
  int srcIndex = from - 1;
  int dstIndex = to - 1;

  // checks for no disks at the source rod
  if (counts[srcIndex] == 0) {
    throw EmptySourceException();
  }

  int movingDisk = towers[srcIndex][counts[srcIndex] - 1];

  // check to make sure moved disk is not bigger than top disk on target rod
  if (counts[dstIndex] > 0) {
    int targetTopDisk = towers[dstIndex][counts[dstIndex] - 1];
    if (movingDisk > targetTopDisk) {
      throw InvalidDiskPlacementException();
    }
  }

  // move disk
  counts[srcIndex]--;
  towers[dstIndex][counts[dstIndex]] = movingDisk;
  counts[dstIndex]++;
}

void HanoiTower::print() {
  // go through each tower
  for (int i = 0; i < 3; i++) {
    cout << "tower_" << (i + 1) << ": ";
    if (counts[i] == 0) {
      cout << "empty";
    } else {
      // go through each disk on tower
      for (int j = 0; j < counts[i]; j++) {
        cout << towers[i][j];
        if (j < counts[i] - 1) {
          cout << " ";
        }
      }
    }
    cout << endl;
  }
}

int main() {
  HanoiTower game;
  int command;

  while (cin >> command && command != 0) {
    try {
      game.moveDisk(command);
    } catch (exception &e) {
      cout << "Exception: " << e.what() << endl;
    }
  }
  game.print();
  return 0;
}