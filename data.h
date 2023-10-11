// This header contains defined constants, input functions,
// and evaluating functions
#ifndef DATA_H
#define DATA_H

#include <chrono>
#include <string>
#include <string_view>

// Information about business
constexpr std::string_view businessName{"HARBOR LANE CAFE"};
constexpr std::string_view businessAddress{"39141 GREEN OAKS BLVD"};
constexpr std::string_view businessCityState{"CHICAGO, IL"};

// Transaction info
constexpr int transCharLimit{7};
constexpr int mccCharLimit{8};

constexpr std::string_view paymentMethode{"CASH"};
// Receipt cost limit
constexpr int subtotalLimit{750};
// In %
constexpr int baseTax{30};

const std::chrono::time_point<std::chrono::system_clock> getCurrentTime();

const std::chrono::year_month_day
getYMD(std::chrono::time_point<std::chrono::system_clock> timeData);

const std::string getRandomHM();

const std::string generateTrans(const int charLimit);

const std::string generateMcc(const int charLimit);

double generateSubtotal(const int subtotalLimit);

double evaluateTax(const double subtotal, const int baseTax);

double evaluateTotal(const double subtotal, const double tax);

#endif
