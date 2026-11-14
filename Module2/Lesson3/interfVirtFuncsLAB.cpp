#include <iostream>
#include <string>

class StringValidator
{
public:
  virtual ~StringValidator() {};
  virtual bool isValid(std::string input) = 0;
};

class ExactValidator : public StringValidator {
public:
  ExactValidator(std::string secret) { this->secret = secret; };
  virtual bool isValid(std::string input);

private:
  std::string secret;
};

bool ExactValidator::isValid(std::string input)
{
  return input == secret;
}

class DummyValidator : public StringValidator {
public:
  virtual bool isValid(std::string input);
};

bool DummyValidator::isValid(std::string input)
{
  return true;
}



using namespace std;

void printValid(StringValidator &validator, string input)
{
  cout << "The string '" << input << "' is "
       << (validator.isValid(input) ? "valid" : "invalid") << endl;
}


int main()
{
  DummyValidator dummy;
  printValid(dummy, "hello");
  cout << endl;

  ExactValidator exact("secret");
  printValid(exact, "hello");
  printValid(exact, "secret");
  return 0;
}