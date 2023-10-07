//Jack Keys || CS303

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

class Employee
{
  public:

    /*Friend Function for << Overload*/

      // pre  -- takes an ostream buffer and an Employee object
      // post -- makes it so that the insertion operator returns the name of the employee ; for use in the LinkedList::printList() function
      friend std::ostream& operator<<(std::ostream& out, const Employee* obj);

    /*Constructors*/

      Employee();
      Employee(std::string nameTS, double payRateTS);

    /*Virtual Functions*/

      // pre  -- takes no arguments
      // post -- calculates vacation days based off of which type of employee the function is called on
      virtual double calculateVacationDays() const = 0;
  
      // pre  -- takes no arguments
      // post -- calculates the pay based off of the type of employee the function is called on
      virtual double calculatePay() const = 0;
  
      // pre  -- takes no arguments
      // post -- calculates contribution based off of the type of employee the function is called on
      virtual double calculateHealthCareContribution() const = 0;
  
      // pre  -- takes no arguments
      // post -- outputs information about the employee to the console
      virtual void printEmployee();


    /*Mutators and Accessors*/

      void setName(std::string nameTS) {this->name = nameTS;}
      void setPayRate(double payRateTS) {this->payRate = payRateTS;}
      std::string getName() {return this->name;}
      double getPayRate() {return this->payRate;}
  
  protected:
  
    std::string name;
    double vacationDays; //will be calculated upon initialization of derived class
    double payRate; //will be monthly salary for professionals and hourly rate for non-professionals
    double healthCareContribution; //will be calculated upon initialization of derived class
    double pay; //will be calculated upon initialization of derived class
};

#endif