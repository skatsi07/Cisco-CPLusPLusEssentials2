#include <iostream>
#include <string>

using namespace std;

const int WHEEL_COUNT = 4;
const int LIGHT_COUNT = 10;

class Engine {
public:
  Engine(const string &capacity) : capacity(capacity) {}

  void print() const { cout << "Engine: " << capacity << endl; }

private:
  string capacity;
};

class Wheel {
public:
  Wheel() : size("") {}
  Wheel(const string &size) : size(size) {}

  void print() const { cout << "Wheel: " << size << endl; }

private:
  string size;
};

class Chassis {
public:
  Chassis(const string &style) : style(style) {}

  void print() const { cout << "Chassis: " << style << endl; }

private:
  string style;
};

class Light {
public:
  Light() : category("") {}
  Light(const string &category) : category(category) {}

  void print() const { cout << "Light: " << category << endl; }

private:
  string category;
};

class Body {
public:
  Body(const string &colour) : colour(colour) {}

  void print() const { cout << "Body: " << colour << endl; }

private:
  string colour;
};

class Car {
public:
  Car(const Engine &engine, const Wheel wheels[], const Chassis &chassis,
      const Light lights[], const Body &body)
      : engine(engine), chassis(chassis), body(body) {
    for (int i = 0; i < WHEEL_COUNT; i++)
      this->wheels[i] = wheels[i];

    for (int i = 0; i < LIGHT_COUNT; i++)
      this->lights[i] = lights[i];
  }

  void print() const {
    engine.print();

    for (int i = 0; i < WHEEL_COUNT; i++)
      wheels[i].print();

    chassis.print();

    for (int i = 0; i < LIGHT_COUNT; i++)
      lights[i].print();

    body.print();
  }

private:
  Engine engine;
  Wheel wheels[WHEEL_COUNT];
  Chassis chassis;
  Light lights[LIGHT_COUNT];
  Body body;
};

int main() {
  Engine engine("1.0");
  Wheel wheels[WHEEL_COUNT] = {Wheel("16inches"), Wheel("16inches"),
                               Wheel("16inches"), Wheel("16inches")};
  Chassis chassis("Normal");
  Light lights[LIGHT_COUNT] = {
      Light("Type 1"), Light("Type 1"), Light("Type 2"), Light("Type 2"),
      Light("Type 3"), Light("Type 3"), Light("Type 4"), Light("Type 4"),
      Light("Type 5"), Light("Type 5")};
  Body body("Black");

  Car car(engine, wheels, chassis, lights, body);
  car.print();

  return 0;
}