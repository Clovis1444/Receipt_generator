// This header outputs values in the console
#ifndef OUTPUT_H
#define OUTPUT_H

#include <chrono>
#include <string>
#include <string_view>

void printReceipt(std::chrono::year_month_day ymd, std::string_view time);
void printHorizontalLine();
void printDate(std::chrono::year_month_day ymd);
void printTime(std::string_view time);
void printTrans(std::string_view trans);
void printMcc(std::string_view mcc);
void printPaymentMethode(std::string_view paymentMethode);
void printSubtotal(std::string_view subtotal);
void printTax(std::string_view tax);
void printTotal(std::string_view total);
void printThanks();
#endif
