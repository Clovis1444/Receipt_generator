// For more info see sourse below
// https://en.cppreference.com/w/cpp/chrono

#include "data.h"
#include <chrono>
// For using time(0) in srand()
#include <ctime>
#include <stdlib.h>
#include <string>
#include <string_view>

// Gets current time from system clock
const std::chrono::time_point<std::chrono::system_clock> getCurrentTime() {
  return std::chrono::system_clock::now();
}

// This function returns YMD type object.
// To get current time YDM use std::chrono::system_clock::now() as a parameter
// Or use getCurrentTime()
const std::chrono::year_month_day
getYMD(std::chrono::time_point<std::chrono::system_clock> timeData) {
  return std::chrono::floor<std::chrono::days>(timeData);
}

// Generates ranmdo time in "07:10 AM" format
const std::string getRandomHM() {
  srand(static_cast<unsigned int>(time(0)));
  const int h{rand() % 13};
  const int m{rand() % 60};
  std::string am_pm{};
  if (rand() % 2) {
    am_pm = "AM";
  } else {
    am_pm = "PM";
  }

  if (m < 10) {
    return std::to_string(h) + ":0" + std::to_string(m) + " " + am_pm;
  } else {
    return std::to_string(h) + ":" + std::to_string(m) + " " + am_pm;
  }
}

// Generates random hex string.
// Specify the number of characters in the string in parameter.
const std::string generateTrans(const int charLimit) {
  srand(static_cast<unsigned int>(time(0)));
  constexpr char hexdigit[17]{"0123456789ABCDEF"};
  std::string trans{hexdigit[rand() % static_cast<int>(sizeof(hexdigit)) - 1]};
  for (int i = 0; i < charLimit - 1; ++i) {
    trans += hexdigit[rand() % static_cast<int>(sizeof(hexdigit)) - 1];
  }
  return trans;
}

// Almost same as generateTrans, exscept "+ rand() % 10" on line 61.
// This is done so that functions do not have the same seed.
// Generates random hex string.
// Specify the number of characters in the string in parameter.
const std::string generateMcc(const int charLimit) {
  srand(static_cast<unsigned int>(time(0)) +
        static_cast<unsigned int>(rand() % 10));
  constexpr char hexdigit[17]{"0123456789ABCDEF"};
  std::string mcc{hexdigit[rand() % static_cast<int>(sizeof(hexdigit)) - 1]};
  for (int i = 0; i < charLimit - 1; ++i) {
    mcc += hexdigit[rand() % static_cast<int>(sizeof(hexdigit)) - 1];
  }
  return mcc;
}

// Generates receipt's cost.
// Specify the receipt's cost limit in parameter.
double generateSubtotal(const int subtotalLimit) {
  srand(static_cast<unsigned int>(time(0)));
  const double cost{static_cast<double>(rand() % subtotalLimit)};
  return cost;
}

// subtotal * baseTax / 100
double evaluateTax(const double subtotal, const int baseTax) {
  return subtotal * static_cast<double>(baseTax) / 100;
}

// subtotal + tax
double evaluateTotal(const double subtotal, const double tax) {
  return subtotal + tax;
}
