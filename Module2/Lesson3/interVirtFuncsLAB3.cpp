#include <cctype>
#include <iostream>
#include <string>

using namespace std;

class StringValidator {
public:
  virtual ~StringValidator() {};
  virtual bool isValid(std::string input) = 0;
};

class MinLengthValidator : public StringValidator {
public:
  MinLengthValidator(int min) { this->min = min; }
  virtual bool isValid(std::string input);

private:
  int min;
};

bool MinLengthValidator::isValid(std::string input) {
  return input.length() >= min;
}

class MaxLengthValidator : public StringValidator {
public:
  MaxLengthValidator(int max) { this->max = max; }
  virtual bool isValid(std::string input);

private:
  int max;
};

bool MaxLengthValidator::isValid(std::string input) {
  return input.length() <= max;
}

class LengthValidator : public StringValidator {
public:
  LengthValidator(int min, int max);
  virtual bool isValid(std::string input);

private:
  MinLengthValidator min_validator;
  MaxLengthValidator max_validator;
};

LengthValidator::LengthValidator(int min, int max)
    : min_validator(min), max_validator(max) {}

bool LengthValidator::isValid(std::string input) {
  return (min_validator.isValid(input) && max_validator.isValid(input));
}

class minOneUpperValidator : public StringValidator {
public:
  virtual bool isValid(string input);
};

bool minOneUpperValidator::isValid(string input) {
  for (int i = 0; i < input.length(); i++) {
    if (isupper(input[i])) {
      return true;
    }
  }
  return false;
}

class minOneLowerValidator : public StringValidator {
public:
  virtual bool isValid(string input);
};

bool minOneLowerValidator::isValid(string input) {
  for (int i = 0; i < input.length(); i++) {
    if (islower(input[i])) {
      return true;
    }
  }
  return false;
}

class minOneSpecialCharValidator : public StringValidator {
public:
  virtual bool isValid(string input);
};

bool minOneSpecialCharValidator::isValid(string input) {
  for (int i = 0; i < input.length(); i++) {
    if (!isalnum(input[i]) && !isspace(input[i])) {
      return true;
    }
  }
  return false;
}

void printValid(StringValidator &validator, string input) {
  cout << "The string '" << input << "' is "
       << (validator.isValid(input) ? "valid" : "invalid") << endl;
}

int main() {
  LengthValidator validator(4, 8);
  printValid(validator, "hi");        // invalid
  printValid(validator, "hello");     // valid
  printValid(validator, "wonderful"); // invalid

  minOneUpperValidator upper;
  printValid(upper, "hello"); // invalid
  printValid(upper, "Hello"); // valid

  minOneSpecialCharValidator special;
  printValid(special, "Hello123");  // invalid
  printValid(special, "Hello@123"); // valid

  return 0;
}