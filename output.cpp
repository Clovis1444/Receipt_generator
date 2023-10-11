#include "output.h"
#include "data.h"
#include <chrono>
#include <iostream>
#include <string>
#include <string_view>

void printReceipt(std::chrono::year_month_day ymd, std::string_view time) {
  std::cout << "\n\n\n";
  std::cout << businessName << "\n";
  std::cout << businessAddress << "\n";
  std::cout << businessCityState << "\n";
  printHorizontalLine();

  printDate(ymd);
  printTime(time);
  printHorizontalLine();

  printTrans(generateTrans(transCharLimit));
  printMcc(generateMcc(mccCharLimit));
  printPaymentMethode(paymentMethode);
  printHorizontalLine();

  double subtotal{generateSubtotal(subtotalLimit)};
  double tax{evaluateTax(subtotal, baseTax)};
  double total{evaluateTotal(subtotal, tax)};
  printSubtotal(std::to_string(subtotal));
  printTax(std::to_string(tax));
  printTotal(std::to_string(total));

  printThanks();
}

void printHorizontalLine() { std::cout << "-------------------------\n"; }

void printDate(std::chrono::year_month_day ymd) {
  std::cout << ymd.month() << "/" << ymd.day() << "/" << ymd.year() << "     ";
}

void printTime(std::string_view time) { std::cout << time << "\n"; }

void printTrans(std::string_view trans) {
  std::cout << "TRANS - " << trans << "\n";
}

void printMcc(std::string_view mcc) { std::cout << "MCC - " << mcc << "\n"; }

void printPaymentMethode(std::string_view paymentMethode) {
  std::cout << "PAYMENT - " << paymentMethode << "\n";
}

void printSubtotal(std::string_view subtotal) {
  std::cout << "SUBTOTAL: $" << subtotal << "\n";
}

void printTax(std::string_view tax) { std::cout << "TAX: $" << tax << "\n"; }

void printTotal(std::string_view total) {
  std::cout << "TOTAL: $" << total << "\n";
}

void printThanks() {
  std::cout << "\n\n";
  std::cout << "PLEASE COME AGAIN\n";
  std::cout << "THANK YOU\n";
}
