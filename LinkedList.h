//Jack Keys || CS303

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdexcept>
#include <iostream>
#include <string>

template <typename dataType>
class LinkedList
{

public:
    
  //node to hold data and pointer to next node
  struct node
    {
      dataType data;
      node* next;

      //constructor for node
      node(dataType dataTS, node* nextTS = nullptr) : data(dataTS), next(nextTS) {}
    };

  //nested iterator class to make iterating through the list much easier
  class Iterator
    {
      public:
  
        //constructor for iterator object
        Iterator(node* currentTS) : currentItem(currentTS) {}
  
        //overloaded ++ operator
          // pre  -- takes no arguments
          // post -- stores the next node of the linked list into the iterator's currentItem
        Iterator& operator++()
        {
          if (this->currentItem == nullptr)
          {
            throw std::runtime_error("cannot iterate past end()");
          }
          
          this->currentItem = currentItem->next;
          return *this;
        }
        
        //overloaded * operator
          // pre  -- takes no arguments
          // post -- returns reference to the data contained in the node stored in currentItem
        dataType& operator*()
        {
          if (this->currentItem == nullptr)
          {
            throw std::runtime_error("cannot dereference end()");
          }
        
          return currentItem->data;
        }
  
        //overloaded != operator
          //pre  -- takes the right hand side of a default != operation as argument
          //post -- returns false if the lhs is the same as the rhs ; else true
        bool operator!=(const Iterator& rhs)
        {
          return this->currentItem != rhs.currentItem;
        }
        
        //function to make my life easier
          // pre  -- takes no arguments
          // post -- returns a reference to the node itself stored in currentItem
        node* getCurrent()
        {
          if (this->currentItem == nullptr)
          {
            throw std::runtime_error("node is outside of the list (pointing to nullptr)");
          }
        
          return this->currentItem;
        }
  
      private:
      
        node* currentItem;
    };

  //default constructor
  LinkedList() : numItems(0), head(nullptr), tail(nullptr) {}
  
  //constructor -- takes a node and adds it to the linked list
  LinkedList(node* headTS) : numItems(1), head(headTS), tail(headTS) {}

  // pre  -- takes no arguments
  // post -- returns an iterator containing the first element of the list in its currentItem
  Iterator begin() {return Iterator(this->head);}
  
  // pre  -- takes no arguments
  // post -- returns an iterator containing the nullptr as its currentItem
  Iterator end() {return Iterator(nullptr);}
  
  // pre  -- takes a variable of type dataType
  // post -- appends the variable to the front of the list
  void push_front(dataType toAdd)
    {
      node* nodeToAdd = new node(toAdd); //create a new node with the data to be added to the list
    
      //if list is empty
      if (numItems == 0)
      {
        this->head = nodeToAdd; //set the head and the tail pointers to the added node
        this->tail = nodeToAdd;
      }
    
      //if there is already stuff in the list
      else
      {
        nodeToAdd->next = this->head; //set nodeToAdd's next node to the current head pointer
        this->head = nodeToAdd; //update the current head pointer to point to nodeToAdd instead of the old front node
      }
    
      numItems++; //increment numItems
    }
  
  // pre  -- takes a variable of type dataType
  // post -- appends the variable to the end of the list
  void push_back(dataType toAdd)
    {
      node* nodeToAdd = new node(toAdd);
  
      //if the list is empty
      if (numItems == 0)
      {
        this->head = nodeToAdd; //set the head and the tail pointers to the added node
        this->tail = nodeToAdd;
      }
    
      //if the list isn't empty
      else
      {
        this->tail->next = nodeToAdd; //set the tail's next to nodeToAdd
        this->tail = nodeToAdd; //update the tail so that it points to nodeToAdd instead of the old tail node
      }
    
      numItems++; //increment numItems
    }
  
  // pre  -- takes no arguments
  // post -- removes the first element of the list
  void pop_front()
    {
      //if the list is empty, throw error
      if (numItems == 0)
      {
        throw std::runtime_error("cannot remove items from an empty list");
      }

      node* delNode = this->head;  //create a reference to the node that will be removed

      //if there is one item in the list
      if (numItems == 1)
      {
        this->head = nullptr; //set the head and tail nodes to nullptr; the list is now empty
        this->tail = nullptr;
      }

      //if there is more than one item in the list
      else
      {
        this->head = this->head->next; //update the head node to contain the second element of the list
      }
      
      delete delNode; //free up memory
      delNode = nullptr;

      numItems--; //decrement numItems
    }
  
  // pre  -- takes no arguments
  // post -- removes the last element of the list
  void pop_back()
    {
      //if the list is empty, throw error
      if (numItems == 0)
      {
        throw std::runtime_error("cannot remove items from an empty list");
      }

      node* delNode = this->tail; //create a reference to the node that will be removed
      node* secondToLastReference = nullptr; //a node that will hold the second to last element in the list

      //if there is one item in the list
      if (numItems == 1)
      {
        this->head = nullptr;
        this->tail = nullptr;
      }

      //if there is more than one item in the list
      else
      {
        Iterator it = this->begin(); //create an iterator for traversing the list
        
        //iterate through the list until a reference to the second to last element of the list can be made
        //after the loop terminates, it.getCurrent() should contain a reference to the second to last item of the list
        for ( ; it.getCurrent()->next->next != nullptr ; ++it) {}
        secondToLastReference = it.getCurrent();

        this->tail = secondToLastReference; //update the tail to hold the second to last element
        secondToLastReference->next = nullptr; //update the second to last element to point to nullptr instead of the element to be removed
      }

      delete delNode; //free up memory
      delNode = nullptr;

      numItems--; //decrement numItems
    }
  
  // pre  -- takes no arguments
  // post -- returns the first element of the list
  dataType front()
    {
      if (numItems == 0)
      {
        throw std::runtime_error("tried to access element from empty list");
      }
      
      return this->head->data;  
    }
  
  // pre  -- takes no arguments
  // post -- returns the last element of the list
  dataType back()
    {
      if (numItems == 0)
      {
        throw std::runtime_error("tried to access element from empty list");
      }
      
      return this->tail->data;
    }
  
  // pre  -- takes no arguments
  // post -- returns true if numItems = 0 ; else returns false
  bool empty() {return numItems == 0;}
  
  // pre  -- takes an integer index and a value
  // post -- inserts the value at the specified index in the list
  void insert(int index, const dataType& toInsert)
    {
      node* nodeToAdd = new node(toInsert);
      Iterator it = this->begin();
    
      //if the passed index is greater than the max index of the list, push the passed value onto the end of the list
      if (index >= numItems-1)
      {
        this->push_back(toInsert);
        return;
      }
    
      //if index is 0, call the push front function to add the element
      if (index == 0)
      {
        this->push_front(toInsert);
        return;
      }
    
      //if index is less than 1 throw an error
      if (index < 0)
      {
        throw std::runtime_error("tried to insert at a negative index");
      }
    
      //when this loop terminates, the iterator will contain a reference to the element one index before the target in the list
      for (unsigned int i = 0 ; i < index-1 ; ++i)
        {
          ++it;
        }
    
      node* tempReference = it.getCurrent();

      //note: nodeToAdd is being inserted in between tempReference and tempReference->next
      nodeToAdd->next = tempReference->next; //set nodeToAdd's next to tempReference->next
      tempReference->next = nodeToAdd; //tempReference is now the item before nodeToAdd, so set its next to point to nodeToAdd
      numItems++; //increment numItems
      
    }
  
  // pre  -- takes an integer index
  // post -- removes the element in the linked list at the specified 
  //         index and returns true ; if the index is outside of the list, returns false
  bool remove(int index)
    {
      //if index is negative, throw error
      if (index < 0)
      {
        throw std::runtime_error("tried to pass negative index");
      }

      //if index is outside of the list
      if (index >= numItems)
      {
        return false;
      }

      //if index is the last element
      if (index == numItems-1)
      {
        this->pop_back();
        return true;
      }

      //if index is the first element
      if (index == 0)
      {
        this->pop_front();
        return true;
      }

      //if the index is in the middle of the list
      else
      {
        int counter = 0;
        node *delNode, *previousNode;
        Iterator it = this->begin();

        //when this loop terminates, the iterator should contain the node before the one that will be removed
        for ( ; counter != index-1 ; ++it)
          {
            counter++;
          }

        previousNode = it.getCurrent(); //previous node contains the element before the one to be removed
        delNode = previousNode->next; //this contains the item to be removed from the list
        previousNode->next = delNode->next; //patch the hole in the list that will be caused from the deletion

        delete delNode; //free up memory
        delNode = nullptr;
        
        numItems--; //decrement numItems

        return true;
      }
    }
  
  // pre  -- takes a value of type dataType
  // post -- if the specified value is in the list, returns the index of the first instance of it ; else returns the size of the list
  int find(const dataType& toFind)
    {
      int counter = 0; //keeps track of the index
    
      //iterate the linked list
      for (Iterator it = this->begin() ; it != this->end() ; ++it)
        {
          if (it.getCurrent()->data == toFind)
          {
            return counter; //if the value is found, return the index at which it is found
          }
          counter++;
        }
    
      return numItems; //if the value is not found, return numItems
    }
  
  // pre  -- takes no arguments
  // post -- outputs the elements of the list to the console for debugging purposes
  void printList()
    {
      for (Iterator it = this->begin() ; it != this->end() ; ++it)
        {
          std::cout << it.getCurrent()->data << " ";
        }
      
     std::cout << std::endl;
    }

  // pre  -- takes no arguments
  // post -- returns the size of the list
  int size() {return this->numItems;}
  
private:
  
  int numItems;
  node* head;
  node* tail;

};

#endif