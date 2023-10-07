//Jack Keys || CS303

#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Employee.h"
#include "Nonprofessional.h"
#include "Professional.h"

//Example Program

int main() 
{
  
  /*Linked List Demonstration*/
  
    LinkedList<std::string> myList;
    bool tempBool;
    int tempInt;
  
    myList.push_back("middle");
    std::cout << "starting list: ";
    myList.printList();
    std::cout << "----------" << std::endl << std::endl;
  
    //push_back()
      std::cout << "calling myList.push_back(\"back\")" << std::endl;
      myList.push_back("back");
      std::cout << "current list: ";
      myList.printList();
      std::cout << "----------" << std::endl << std::endl;
  
    //push_front()
      std::cout << "calling myList.push_front(\"front\")" << std::endl;
      myList.push_front("front");
      std::cout << "current list: ";
      myList.printList();
      std::cout << "----------" << std::endl << std::endl;
  
    //front()
      std::cout << "myList.front() = " << myList.front() << std::endl;
      std::cout << "----------" << std::endl << std::endl;
  
    //back()
      std::cout << "myList.back() = " << myList.back() << std::endl;
      std::cout << "----------" << std::endl << std::endl;
  
    //insert()
      std::cout << "calling myList.insert(1, \"insert\")" << std::endl;
      myList.insert(1, "insert");
      std::cout << "current list: ";
      myList.printList();
      std::cout << "----------" << std::endl << std::endl;
  
    //insert() [beyond end of list]
      std::cout << "calling myList.insert(100, \"insertBeyondEnd\")" << std::endl;
      myList.insert(100, "insertBeyondEnd");
      std::cout << "current list: ";
      myList.printList();
      std::cout << "----------" << std::endl << std::endl;
  
    //remove()
      std::cout << "calling myList.remove(4)" << std::endl;
      tempBool = myList.remove(4);
      std::cout << "current list: ";
      myList.printList();
      std::cout << "Boolean return value (1 if successful 0 if fail) = " << tempBool << std::endl;
      std::cout << "----------" << std::endl << std::endl;
  
    //remove() [beyond end of list]
      std::cout << "calling myList.remove(100)" << std::endl;
      tempBool = myList.remove(100);
      std::cout << "current list: ";
      myList.printList();
      std::cout << "Boolean return value (1 if successful 0 if fail) = " << tempBool << std::endl;
      std::cout << "----------" << std::endl << std::endl;
  
    //find()
      std::cout << "calling myList.find(\"insert\")" << std::endl;
      tempInt = myList.find("insert");
      std::cout << "current list: ";
      myList.printList();
      std::cout << "return value = " << tempInt << std::endl;
      std::cout << "----------" << std::endl << std::endl;
  
    //find() [non-existent value]
      std::cout << "calling myList.find(\"not here\")" << std::endl;
      tempInt = myList.find("not here");
      std::cout << "current list: ";
      myList.printList();
      std::cout << "return value = " << tempInt << std::endl;
      std::cout << "----------" << std::endl << std::endl;
  
    //pop_back()
      std::cout << "calling myList.pop_back()" << std::endl;
      myList.pop_back();
      std::cout << "current list: ";
      myList.printList();
      std::cout << "----------" << std::endl << std::endl;
  
    //pop_front()
      std::cout << "calling myList.pop_front()" << std::endl;
      myList.pop_front();
      std::cout << "current list: ";
      myList.printList();
      std::cout << "----------" << std::endl << std::endl;
  
    //empty()
      std::cout << "calling myList.empty()" << std::endl;
      tempBool = myList.empty();
      std::cout << "current list: ";
      myList.printList();
      std::cout << "Boolean return value = " << tempBool << std::endl;
      std::cout << "----------" << std::endl << std::endl;

  /*Employee Demonstration*/

    //initialize objects and store in LinkedList
      Employee* e1 = new Nonprofessional("Bob", 25.0, 36);
      Employee* e2 = new Professional("Mike", 2500.0, 3);
      LinkedList<Employee*> empList;
      empList.push_back(e1);
      empList.push_back(e2);
  
    //runtime polymorphism / displaying employee's metrics / using my iterator class for ranged based for loop
      for (auto employee : empList)
        {
          employee->printEmployee();
          std::cout << std::endl;
        }
}