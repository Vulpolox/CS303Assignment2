//Jack Keys || CS303

#ifndef PROFESSIONAL_H
#define PROFESSIONAL_H

#include "Employee.h"

class Professional : public Employee
{

public:

  /*Constructors*/
  
    Professional();
    Professional(std::string nameTS, double payRateTS, double monthsWorked);
  
  /*Overridden Function Declarations*/
  
    // pre  -- takes no arguments
    // post -- calculates vacations days as a flat rate per months worked ; 1 month worked = 3 vacation days
    double calculateVacationDays() const override;
    
    // pre  -- takes no arguments
    // post -- calculates weekly pay based off of payRate (payRate refers to monthly salary):
    //         pay = payRate / 4.0
    double calculatePay() const override;
    
    // pre  -- takes no arguments
    // post -- calculates health care contribution based off of payRate
    //         healthCareContribution = 0.05 * payRate
    double calculateHealthCareContribution() const override;
    
    // pre  -- takes no arguments
    // post -- prints professional employee data
    void printEmployee() override;
  
  /*Accessors and Mutators*/
  
    void setMonthsWorked(double monthsWorkedTS) {this->monthsWorked = monthsWorkedTS;}
    double getMonthsWorked() {return this->monthsWorked;}

private:

  double monthsWorked;

};

#endif