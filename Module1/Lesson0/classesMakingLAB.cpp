#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
  string name;
  int    age;
  string hairColour;
};

void print(Person* person)
{
  cout << person->name << " is " << person->age << " years old" << endl;
  cout << person->name << " has " << person->hairColour << " hair" << endl;
}


int main()
{
  Person person;
  person.name = "Harry";
  person.age  = 23;
  person.hairColour = "brown";

  Person person2;
  person2.name = "Jack";
  person2.age = 51;
  person2.hairColour = "green";

  cout << "Meet " << person.name << endl;
  print(&person);

  cout << "Meet " << person2.name << endl;
  print(&person2);

  return 0;
}