#include <iostream>
#include <string>

using namespace std;

// base player class
class Player {
public:
  Player(string playerName) {
    name = playerName;
    score = 0;
  }
  virtual ~Player() {}

  virtual int takeTurn() = 0;

  void addPoint() { score++; } // if win
  int getScore() { return score; }
  string getName() { return name; }

protected:
  string name;
  int score;

  int rollDie() { return (rand() % 6) + 1; }
};

// human class sub-class of parent player class
class HumanPlayer : public Player {
public:
  HumanPlayer(string playerName) : Player(playerName) {}

  virtual int takeTurn() {
    cout << name << ", press Enter to roll your die...";
    cin.get();
    int roll = rollDie();
    cout << name << " rolled a " << roll << "!" << endl;
    return roll;
  }
};

// computer class sub0class of parent player class
class BotPlayer : public Player {
public:
  BotPlayer(string playerName) : Player(playerName) {}

  virtual int takeTurn() {
    int roll = rollDie();
    cout << name << " rolled a " << roll << "!" << endl;
    return roll;
  }
};

// controller dice game class
class DiceGame {
public:
  DiceGame(Player *p1, Player *p2, int totalRounds) {
    player1 = p1;
    player2 = p2;
    rounds = totalRounds;
  }

  void play();

private:
  Player *player1;
  Player *player2;
  int rounds;

  void printWinner();
};

void DiceGame ::play() {
  cout << "=== Dice Battle Game (" << rounds << " Rounds) ===" << endl;

  for (int r = 1; r <= rounds; r++) {
    cout << "\n--- Round " << r << " ---" << endl;
    int roll1 = player1->takeTurn();
    int roll2 = player2->takeTurn();

    if (roll1 > roll2) {
      cout << "-> " << player1->getName() << " wins the round!" << endl;
      player1->addPoint();
    } else if (roll2 > roll1) {
      cout << "-> " << player2->getName() << " wins the round!" << endl;
      player2->addPoint();
    } else {
      cout << "-> Tie :/ No points awarded!" << endl;
    }
  }

  printWinner();
}

void DiceGame::printWinner() {
  cout << "\n=== FINAL SCORE ===" << endl;
  cout << player1->getName() << ": " << player1->getScore() << endl;
  cout << player2->getName() << ": " << player2->getScore() << endl;

  if (player1->getScore() > player2->getScore()) {
    cout << player1->getName() << " wins the game!" << endl;
  } else if (player2->getScore() > player1->getScore()) {
    cout << player2->getName() << " wins the game!" << endl;
  } else {
    cout << "It is a draw..." << endl;
  }
}

int main() {

  HumanPlayer human("Player");
  BotPlayer bot("Computer");

  DiceGame game(&human, &bot, 3);
  game.play();

  return 0;
}