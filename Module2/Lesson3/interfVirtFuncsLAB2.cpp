#include <iostream>
#include <string>

class StringValidator
{
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

bool MinLengthValidator::isValid(std::string input)
{
  return input.length() >= min;
}

class MaxLengthValidator : public StringValidator {
public:
  MaxLengthValidator(int max) { this->max = max; }
  virtual bool isValid(std::string input);

private:
  int max;
};

bool MaxLengthValidator::isValid(std::string input)
{
  return input.length() <= max;
}

class PatternValidator : public StringValidator {
public:
  PatternValidator(std::string pattern) { this->pattern = pattern; }
  virtual bool isValid(std::string input);

private:
  std::string pattern;
};

bool PatternValidator::isValid(std::string input)
{
  // An empty pattern matches anything
  if (pattern.empty()) {
    return true;
  }

  // If the input is shorter than the pattern, it can never match
  if (input.length() < pattern.length()) {
    return false;
  }

  // Outer loop: slide the pattern across every valid starting position in 'input'
  // some AI used for pattern matching algorithm
  for (size_t i = 0; i <= input.length() - pattern.length(); ++i) {
    bool match = true;

    // Inner loop: check every character of 'pattern' against the substring starting at 'i'
    for (size_t j = 0; j < pattern.length(); ++j) {
      unsigned char p = static_cast<unsigned char>(pattern[j]);
      unsigned char c = static_cast<unsigned char>(input[i + j]);

      if (p == 'D') {
        if (!std::isdigit(c)) {
          match = false;
          break;
        }
      } else if (p == 'A') {
        if (!std::isalpha(c)) {
          match = false;
          break;
        }
      } else if (std::islower(p)) {
        if (std::tolower(c) != p) {
          match = false;
          break;
        }
      } else if (p == '?') {
        // '?' matches any character (including whitespace), so do nothing
      } else if (std::ispunct(p)) {
        if (c != p) {
          match = false;
          break;
        }
      } else {
        // Fallback for any unexpected pattern characters (e.g., digits or other uppercase letters)
        if (c != p) {
          match = false;
          break;
        }
      }
    }

    // If the entire pattern matched at starting index 'i', the string is valid
    if (match) {
      return true;
    }
  }

  // No matching substring was found anywhere in 'input'
  return false;
}



using namespace std;

void printValid(StringValidator &validator, string input)
{
  cout << "The string '" << input << "' is "
       << (validator.isValid(input) ? "valid" : "invalid") << endl;
}


int main()
{
  cout << "MinLengthValidator" << endl;
  MinLengthValidator min(6);
  printValid(min, "hello");
  printValid(min, "welcome");
  cout << endl;

  cout << "MaxLengthValidator" << endl;
  MaxLengthValidator max(6);
  printValid(max, "hello");
  printValid(max, "welcome");
  cout << endl;

  cout << "PatternValidator" << endl;
  PatternValidator digit("D");
  printValid(digit, "there are 2 types of sentences in the world");
  printValid(digit, "valid and invalid ones");
  cout << endl;

  return 0;
}