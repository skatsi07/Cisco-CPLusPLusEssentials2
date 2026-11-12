#include <iostream>
#include <sstream>

using namespace std;

class FarmAnimal {
public:
  virtual double getWaterConsumption() = 0;
};

class SheepAnimal : public FarmAnimal {
public:
  SheepAnimal(double weight) : weight(weight) {}
  virtual double getWaterConsumption() override {
    return weight / 10*1.1;
  }

private:
  double weight;
};

class HorseAnimal : public FarmAnimal {
public:
  HorseAnimal(double weight) : weight(weight) {}
  virtual double getWaterConsumption() override {
    return weight / 100*6.8;
  }

private:
  double weight;
};

class CowAnimal : public FarmAnimal {
public:
  CowAnimal(double weight) : weight(weight) {}
  virtual double getWaterConsumption() override {
    return weight / 100*8.6;
  };

private:
  double weight;
};


void printConsumption(FarmAnimal &animal) {
  cout << "This animal consumes " << animal.getWaterConsumption()
       << " liters of water" << endl;
}

int main() {
    string input;
    double totalWaterConsumption = 0.0;

    while (getline(cin, input) && !input.empty()) {
        string animal;
        double weight;
        istringstream iss(input);
        iss >> animal >> weight;

        if (animal == "cow") {
            CowAnimal cow(weight);
            totalWaterConsumption += cow.getWaterConsumption();
        } else if (animal == "sheep") {
            SheepAnimal sheep(weight);
            totalWaterConsumption += sheep.getWaterConsumption();
        } else if (animal == "horse") {
            HorseAnimal horse(weight);
            totalWaterConsumption += horse.getWaterConsumption();
        }
    }

    cout << totalWaterConsumption << endl;

    return 0;
}