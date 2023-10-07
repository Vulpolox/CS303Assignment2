//Jack Keys || CS303

#pragma once
#include <iostream>
#include <iomanip>
#include "Nonprofessional.h"

Nonprofessional::Nonprofessional() : Employee()
{
  this->hoursWorked = 0.0;
}

Nonprofessional::Nonprofessional(std::string nameTS, double payRateTS, double hoursWorkedTS) : Employee(nameTS, payRateTS)
{
  this->hoursWorked = hoursWorkedTS;
  
  this->vacationDays = this->calculateVacationDays();
  this->healthCareContribution = this->calculateHealthCareContribution();
  this->pay = this->calculatePay();
}

double Nonprofessional::calculateVacationDays() const
{
  return this->hoursWorked / 100.0;
}

double Nonprofessional::calculateHealthCareContribution() const
{
  return 0.1 * (this->payRate * this->hoursWorked);
}

double Nonprofessional::calculatePay() const
{
  return this->hoursWorked * this->payRate;
}

void Nonprofessional::printEmployee()
{
  std::cout << "Nonprofessional Employee" << std::endl;
  std::cout << "------------------------" << std::endl;
  Employee::printEmployee();
  std::cout << "hour" << std::endl;
  std::cout << std::fixed << std::setprecision(1) << "  Hours Worked: " << this->hoursWorked << std::endl;
  std::cout << std::fixed << std::setprecision(2) << "  Vacation Days Earned: " << this->vacationDays << std::endl;
  std::cout << std::fixed << std::setprecision(2) << "  Weelky Pay Earned: $" << this->pay << std::endl;
  std::cout << std::fixed << std::setprecision(2) << "  Health Care Contribution: $" << this->healthCareContribution << std::endl;

}