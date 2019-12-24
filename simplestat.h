#ifndef SIMPLESTAT_H
#define SIMPLESTAT_H

// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

#include "list.h"
#include "link.h"
#include <iostream>
#include <set>
#include <cmath> //for taking the sqrt of the variance during standard deviation calculation
using namespace std;

// Linked list implementation
template <typename E> 
class Simplestat: public List<E> {
private:
  Link<E>* head; // Pointer to list header
  Link<E>* tail; // Pointer to last element
  Link<E>* curr; // Access to current element
  int cnt; // Size of list
  void init() { // Initialization helper method
    curr = tail = head = new Link<E>;
    cnt = 0;
  }
  void removeall() { // Return link nodes to free store
    while(head != NULL) {
        curr = head;
        head = head->next;
        delete curr;
      }
  }
  void update_mean() {
    double total = 0;
    moveToStart();
    for (int i = 0; i< length(); i++)
    {
      total = total + getValue();
      next();
    }
    //cout << "total is " << total << endl;
    //cout << "count of objects is " << cnt << endl;
    //cout << "so the updted mean is " << total / cnt << endl;
    mean = total / cnt;
    moveToStart();
  }

  void update_max_val() {
    moveToPos(length() -1);
    max_val = getValue();
  }

  void update_min_val() {
    moveToStart();
    min_val = getValue();
  }

  void update_std_dev() {
    update_mean();
    double temp_array[length()];
    
    for (int i = 0; i < length(); i++) //initialize array to 0
    {
      temp_array[i] = 0;
    }
    for (int i = 0; i < length(); i++) //loop for (xi - mean)^2 for each value in list
    {
      temp_array[i] = (getValue() - mean) * (getValue() - mean);
      //cout << "temp_array at position " << i << " is " << temp_array[i] << endl;
      next();
    }
    moveToStart();
    double total = 0;
    for (int i = 0; i < length(); i++) //sum up values for temp_array[]
    {
      total = total + temp_array[i];
    }
    //cout << "total is " << total << endl;
    double variance = 0;
    variance = total / length();
    //cout << "variance is " << variance << endl;
    std_dev = sqrt(variance);
    //cout << "std_dev is " << std_dev << endl;

  }

  void update_median()
  {

    //need to sort before - use selection sort
    sortList();

    //end sorting algorithm
    if (length() % 2 == 1) //odd number of objects in list
    {
      moveToPos(length()/2);
      median = getValue();
      //cout << "median is " << median << endl;
    }
    if (length() % 2 == 0) //even number of objects in list
    {
      //cout << "nothing here yet " << endl;
      moveToPos(length()/2);
      double temp = getValue();
      moveToPos((length()/2) - 1);
      double temp_2 = getValue();
      median = (temp + temp_2) / 2;
      //cout << "median is " << median << endl;
    }
  }

  void sortList()
  {
    //cout << "SORTING" << endl;
    moveToStart();
    for (int i = 0; i < length(); i++)
    {
      double large_temp = getValue();
      int bigIndex = currPos();
      //cout << "In outer loop for the " << i << "th time with the large_temp and bigIndex at " << large_temp << " and " << bigIndex << endl;
      for (int j = 1; j < (length() - i); j++)
      {
        //cout << "In the inner loop for the " << j << "th time" << endl;
        moveToPos(j);
        //cout << "At pos " << j << endl;
        //cout << "comparing " << large_temp << " to " << getValue() << endl;
        if (large_temp < getValue())
        {
          large_temp = getValue();
          bigIndex = currPos();
        }
      }
        //cout << "Swapping..." << endl;
        //cout << "Move object that contains large_temp's value at length of list - i" << endl;

        //cout << "moving to pos length - 1" << endl;
        moveToPos(length() - i);
        //cout << "inserting " << large_temp << " at " << currPos() << endl;
        insert(large_temp, false);
        //cout << "moving to " << bigIndex << endl;
        moveToPos(bigIndex);
        //cout << "removing " << getValue() << " from " << currPos() << endl;
        remove(false);
        //print();
        moveToStart();
    }




  }


  double max_val; //maximum
  double min_val; //minimum
  double mode; //most repeated #
  double median;//middle value
  double mean;//avg
  double std_dev;//standard deviation
  int latest_value; //update all stats with this value
  

//calculating functions
void find_mode(double numberSet) {
  
}

void find_median(double numberSet) {

}

void find_mean(double numberSet) {
  
}

void find_SD(double numberSet) {

}

void find_min(double numberSet) {

}

void find_max(double numberSet) {

}

public:
  Simplestat(int size = 10) {
    init(); // Constructor replace defaultSize (now 10) with the default you want otherwise leave empty
    max_val = 0; //maximum
    min_val = 0; //minimum
    mode = 0; //most repeated #
    median= 0;//middle value
    mean = 0;//avg
    std_dev = 0;//standard deviation
    latest_value = 0; //update all stats with this value

  }
  ~Simplestat() { // Be very careful when you copy from pdf the tilde will not get copied properly so be sure to replace with actual
    removeall(); // Destructor
  }

  void removen(int n)
   {
      int temp = currPos();
      for (int i = 0; i < n; i++)
      {
         remove(true);
         moveToPos(temp);
      }
   }

  template<typename Container>
  void feed(Container& cont)
   {
      for (auto it : cont)
         append(it, true);
   }

  void print() // Print list contents
  {
    moveToStart();
    cout << "List is: ";
    for (int i = 0; i < length(); i++)
    {
      cout << getValue() << " ";
      next();
    }
    cout << endl;
    moveToStart();
  }
  void clear() {
    removeall();
    init(); // Clear list
  }

// Insert "it" at current position
  void insert(const E& it, bool update_stats) {
    //std::cout << "Its in" << std::endl;

    curr->next = new Link<E>(it, curr->next);
    if (tail == curr) tail = curr->next; // New tail
    cnt++;
    if (update_stats == true)
    { 
      update_mean();
      update_std_dev();
      update_median();
      update_min_val();
      update_max_val();
    }
  }


  void append(const E& it, bool stats_update) { // Append "it" to list
    tail = tail->next = new Link<E>(it, NULL);
    cnt++;
    if (stats_update == true)
    { 
      update_mean();
      update_std_dev();
      update_median();
      update_min_val();
      update_max_val();
    }
  }
  // Remove and return current element
  E remove(bool update_stats) {
    Assert(curr->next != NULL, "No element");
    E it = curr->next->element; // Remember value
    Link<E>* ltemp = curr->next; // Remember link node
    if (tail == curr->next) tail = curr; // Reset tail
    curr->next = curr->next->next; // Remove from list
    delete ltemp; // Reclaim space
    cnt--; // Decrements the count
    if (update_stats == true)
    {
      update_mean();
      update_std_dev();
      update_median(); 
      update_min_val();
      update_max_val();     
    }

    return it;
  }





  // Place curr at list start
  void moveToStart() {
    curr = head;
  }
  // Place curr at list end
  void moveToEnd(){
    curr = tail;
  }
  // Move curr one step left; no change if already at front
  void prev() {
    if (curr == head) return; // No previous element
    Link<E>* temp = head;
    // March down list until we find the previous element
    while (temp->next!=curr) temp=temp->next;
    curr = temp;
  }
  // Move curr one step right; no change if already at end
  void next(){
    if (curr != tail) curr = curr->next;
  }
  int length() const {
    return cnt; } // Return length
  // Return the position of the current element
  int currPos() const {
    Link<E>* temp = head;
    int i;
    for (i=0; curr != temp; i++)
      temp = temp->next;
    return i;
  }
  // Move down list to "pos" position
  void moveToPos(int pos) {
    Assert ((pos>=0)&&(pos<=cnt), "Position out of range");
    curr = head;
    for(int i=0; i<pos; i++) curr = curr->next;
  }
  const E& getValue() const { // Return current element
    Assert(curr->next != NULL, "No value");
    return curr->next->element;
  }
  void reverse(){
    Simplestat<E> result(10);
    E it;
    for (int i = 0; i < 8; i++) {
        curr = head;

    //while (curr != NULL) {
        it = remove(false);
        result.insert(it, false);
        //cout << "Its in" << endl;

       }
    curr = head;
    this->head = result.head;
  }
  bool isAtEnd() { return curr == tail; }
  
  E &operator[] (int index)
  {
     moveToPos(index);
     E temp = getValue();
     return temp;
   }

  std::set<int> unique_set()
  {
    std::set<int> unique;
    std::set<int>::iterator it;

    moveToStart();
    for (int i = 0; i < length() ; i++)
    {
       unique.insert(getValue());
       next();
    }

    return unique;

  }

  int unique_length()
  {
    std::set<int> unique = unique_set();
    return unique.size();
  }

  void unique_Print()
  {
    std::set<int> unique = unique_set();
    for(auto itr = unique.begin(); itr != unique.end(); itr++)
    cout << *itr << " ";
  }

 //getters
double get_mode() { return mode; }
double get_median() { return median; }
double get_mean() { return mean; }
double get_SD() { return std_dev; }
double get_min() { return min_val; }
double get_max() { return max_val; }

};

#endif // SIMPLESTAT_H