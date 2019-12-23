#include "link.h"
#include "alist.h"
#include "llist.h"

#include <iostream>
using namespace std;

//template <typename E>
//DLink<E>* DLink<E>::freelist = NULL;  // The freelist head pointer is actually created here

int main(int argc, char *argv[])
{
  cout << "CREATING EMPTY OBJECT" << endl;
  LList<double> statistics;
  
  cout <<"ADDING 10 ELEMENTS TO LIST" << endl;
  for (int i = 0; i < 10; i++)
  {
    statistics.append(i);
  }
  cout << "PRINTING LIST" << endl;
  statistics.print();

  cout << "THE MEAN IS" << endl;
  cout << statistics.get_mean() << endl;
  cout << "PRINTING LIST" << endl;
  statistics.print();

  cout << "DEMO-ing removing an object " << endl;
  statistics.remove();

  cout << "THE MEAN IS:" << endl;
  cout << statistics.get_mean() << endl;

  cout << "Length of linked list is " << statistics.length() << endl;

  //printing all  objects in linked list
  statistics.print();
  cout << endl;

  cout << "THE MEAN IS:" << endl;
  cout << statistics.get_mean() << endl;

  cout << "REMOVING DATA FROM n PLACE IN LIST (n = 5)" << endl;
  statistics.moveToPos(5);
  statistics.remove();

  cout << "PRINTING LIST" << endl;
  statistics.print();

  cout << "THE STATS ARE:" << endl;
  cout << "mean: " << statistics.get_mean() << endl;
  cout << "min: " << statistics.get_min() << endl;
  cout << "max: "<< statistics.get_max() << endl;
  cout << "median: " << statistics.get_median() << endl;
  cout << "standard deviation: " << statistics.get_SD() << endl;
  cout << "mode: " << statistics.get_mode() << endl;





}

/* 

EXAMPLE CODE FROM PROFESSOR

std::cout << "All is good" << "\n";

  AList<int> int_array_list(20);
  LList<int> int_linked_list;
  DLList<int> int_doubly_linked_list;

  for (int i = 0; i < 20; i++)
    {
      int_array_list.append(i);// Try this with i > 20 and se that at i = 21 (> maxSize) you will see the assertion failing with the message "Assertion Failed: List capacity exceeded"
      int_linked_list.append(i);// Default size is 10 but no warning as list allow dynamic resizing
      int_doubly_linked_list.append(i);// Default size is 10 but no warning as list allow dynamic resizing
    }

  std::cout << "In the array list, the current length is: " <<int_array_list.length() << "  current node, " <<   int_array_list.remove() << " has been removed" << " the new length is: " <<int_array_list.length() <<"\n";

  std::cout << "In the singly linked list, the current length is: " <<int_linked_list.length() << "  current node, " <<   int_linked_list.remove() << " has been removed" << " the new length is: " <<int_linked_list.length() <<"\n";

  std::cout << "In the doubly linked list, the current length is: " <<int_doubly_linked_list.length() << "  current node, " <<   int_doubly_linked_list.remove() << " has been removed" << " the new length is: " <<int_doubly_linked_list.length() <<"\n";

  int_array_list.append(100);
  int_linked_list.append(100);
  int_doubly_linked_list.append(100);

  std::cout << "In the array list, the current length is: " <<int_array_list.length() << "  current node, " <<   int_array_list.remove() << " has been removed" << " the new length is: " <<int_array_list.length() <<"\n";

  std::cout << "In the singly linked list, the current length is: " <<int_linked_list.length() << "  current node, " <<   int_linked_list.remove() << " has been removed" << " the new length is: " <<int_linked_list.length() <<"\n";

  std::cout << "In the doubly linked list, the current length is: " <<int_doubly_linked_list.length() << "  current node, " <<   int_doubly_linked_list.remove() << " has been removed" << " the new length is: " <<int_doubly_linked_list.length() <<"\n";

  std::cout << "\n\nStarting stack demo with string reverse ...." << "\n \n";

  // Stack demo. String reverse using stack. You can also use this to check for a Palindrome
  LStack <char> str1;
  std::string input_string = "programming";
  for (int i = 0; i < input_string.length(); i++){
      str1.push(input_string.at(i));
    }
  std::string reversed_string = "";

  for (int i = 0; i < input_string.length(); i++){
      reversed_string += str1.pop(); // Building the reversed string as we pop
    }
  std::cout << "Reversed string for the string " <<input_string << " is " << reversed_string << std::endl; // print reversed
  std::cout << std::endl;

    std::cout << "\n\nStarting queue demo ...." << "\n \n";

  // Queue demo
  LQueue <int> int_stack;
  for (int i = 0; i < 10; i++){
      int_stack.enqueue(i*i); // Insert
    }

  for (int i = 0; i < 10; i++){
      std::cout << "Removed " << i << " th " << " value is " << int_stack.dequeue() << std::endl; // Dequeue operation
    }


  std::cout << "All is good" << "\n";


*/ 