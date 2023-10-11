#include "data.h"
#include "output.h"
#include <chrono>
#include <iostream>
#include <string>

int main() {

  std::chrono::time_point currentTime{getCurrentTime()};
  std::chrono::year_month_day ymd{getYMD(currentTime)};
  const std::string time{getRandomHM()};

  printReceipt(ymd, time);
  return 0;
}
