//Jack Keys || CS303

#ifndef NONPROFESSIONAL_H
#define NONPROFESSIONAL_H

#include "Employee.h"

class Nonprofessional : public Employee
{

public:

  /*Constructors*/
  
    Nonprofessional();
    Nonprofessional(std::string nameTS, double payRateTS, double hoursWorked);
  
  /*Overridden Function Declarations*/
  
    // pre  -- takes no arguments
    // post -- calculates vacation days based off of hours worked ; 100 hours worked = 1 vacation day
    double calculateVacationDays() const override;
    
    // pre  -- takes no arguments
    // post -- calculates weekly pay based off of hours worked and pay rate:
    //         pay = payRate * hoursWorked
    double calculatePay() const override;
    
    // pre  -- takes no arguments
    // post -- calculates value based off of hours worked and pay rate:
    //         healthCareContribution = 0.1 * (payRate * hoursWorked)
    double calculateHealthCareContribution() const override;
    
    // pre  -- takes no arguments
    // post -- prints nonprofessional employee data
    void printEmployee() override;
  
  /*Accessors and Mutators*/
  
    void setHoursWorked(double hoursWorkedTS) {this->hoursWorked = hoursWorkedTS;}
    double getHoursWorked() {return this->hoursWorked;}

private:

  double hoursWorked;

};

#endif