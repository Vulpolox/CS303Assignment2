//Jack Keys || CS303

#pragma once
#include <iostream>
#include <iomanip>
#include "Employee.h"

Employee::Employee()
{
  this->name = "N/A";
  this->payRate = 0.0;

  this->vacationDays = 0.0;
  this->healthCareContribution = 0.0;
  this->pay = 0.0;
}

Employee::Employee(std::string nameTS, double payRateTS)
{
  this->name = nameTS;
  this->payRate = payRateTS;

  this->vacationDays = 0;
  this->healthCareContribution = 0.0;
  this->pay = 0.0;
}

void Employee::printEmployee()
{
  std::cout << "  Name: " << this->name << std::endl;
  std::cout << std::fixed << std::setprecision(2) << "  Pay Rate: $" << this->payRate << " / "; //will specify if pay is per hour or per month in overridden functions
}

std::ostream& operator<<(std::ostream& out, const Employee* obj)
{
  if (obj)
    out << obj->name;
  else
    out << "nullptr";
  return out;
}