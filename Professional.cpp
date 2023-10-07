//Jack Keys || CS303

#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
#include "Professional.h"

Professional::Professional() : Employee()
{
  this->monthsWorked = 0.0;
}

Professional::Professional(std::string nameTS, double payRateTS, double monthsWorkedTS) : Employee(nameTS, payRateTS)
{
  this->monthsWorked = monthsWorkedTS;

  this->vacationDays = this->calculateVacationDays();
  this->healthCareContribution = this->calculateHealthCareContribution();
  this->pay = this->calculatePay();
}

double Professional::calculateVacationDays() const
{
  return std::floor(this->monthsWorked) * 3.0; //the worker has to work the entire month to get their vacation days so take floor
}

double Professional::calculatePay() const
{
  return this->payRate / 4.0; //payRate refers to monthly salary ; divide by 4 to get pay per week
}

double Professional::calculateHealthCareContribution() const
{
  return this->payRate * 0.05; //health care costs are 5% of montly salary
}

void Professional::printEmployee()
{
  std::cout << "Professional Employee" << std::endl;
  std::cout << "------------------------" << std::endl;
  Employee::printEmployee();
  std::cout << "month" << std::endl;
  std::cout << std::fixed << std::setprecision(1) << "  Months Worked: " << this->monthsWorked << std::endl;
  std::cout << std::fixed << std::setprecision(2) << "  Vacation Days Earned: " << this->vacationDays << std::endl;
  std::cout << std::fixed << std::setprecision(2) << "  Weelky Pay Earned: $" << this->pay << std::endl;
  std::cout << std::fixed << std::setprecision(2) << "  Health Care Contribution: $" << this->healthCareContribution << std::endl;
}