#include "link.h"
#include "alist.h"
#include "llist.h"

#include <iostream>
#include <vector>
#include <unordered_set>
#include <list>
#include <array>
using namespace std;

/*

  READ: IN ORDER TO COMPILE, YOU MAY HAVE TO SPECIFY C++ 11 FOR THE COMPILER. FOR EXAMPLE:
  alim@Alims-MacBook:~/cs110c-classwork/group_project_2/LinearStructures_for_project_2$ g++ main.cpp -std=c++11

*/

int main(int argc, char *argv[])
{
  cout << "CREATING EMPTY OBJECT" << endl;
  LList<double> statistics;
  
  cout <<"ADDING 10 ELEMENTS TO LIST" << endl;
  cout <<"Based on for loop, will add 10, 9, 8, 7, 6, 5, 4, 3, 2, 1" << endl;
  for (int i = 10; i > 0; i--)
  {
    statistics.append(i, true);
  }
  cout << "THE STATS WITH ORDER(1) ACCESS ARE:" << endl;
  cout << "mean: " << statistics.get_mean() << endl;
  cout << "min: " << statistics.get_min() << endl;
  cout << "max: "<< statistics.get_max() << endl;
  cout << "median: " << statistics.get_median() << endl;
  cout << "standard deviation: " << statistics.get_SD() << endl;
  cout << "mode: " << statistics.get_mode() << endl;

  cout << "PRINTING LIST" << endl;
  statistics.print();

  //cout << "DEMO-ing removing an object " << endl;
  //statistics.remove(true);

  statistics.moveToStart();
  //statistics.print();

  statistics.removen(2);
  std::vector<int> vect{22, 23, 24};
  std::array<int, 3> arr{25, 26, 27};
  std::set<int> the_set(vect.begin(), vect.end());
  std::list<int> the_list(arr.begin(), arr.end());
  std::unordered_set<int> the_unordered_set(vect.begin(), vect.end());

  cout << "FEEDING CONTAINERS TO LIST. ADDED VECTOR, ARRAY, SET, LIST, AND UNORDERED SET" << endl;
  statistics.feed(vect);
  statistics.feed(arr);
  statistics.feed(the_set);
  statistics.feed(the_list);
  statistics.feed(the_unordered_set);

  /*cout << "THE MEAN IS:" << endl;
  cout << statistics.get_mean() << endl;

  cout << "Length of linked list is " << statistics.length() << endl;

  //printing all  objects in linked list
  statistics.print();
  cout << endl;

  cout << "THE MEAN IS:" << endl;
  cout << statistics.get_mean() << endl;

  cout << "REMOVING DATA FROM n PLACE IN LIST (n = 5)" << endl;
  statistics.moveToPos(5);
  statistics.remove(true);

  cout << "PRINTING LIST" << endl;*/
  statistics.print();

  cout << "THE STATS WITH ORDER(1) ACCESS ARE:" << endl;
  cout << "mean: " << statistics.get_mean() << endl;
  cout << "min: " << statistics.get_min() << endl;
  cout << "max: "<< statistics.get_max() << endl;
  cout << "median: " << statistics.get_median() << endl;
  cout << "standard deviation: " << statistics.get_SD() << endl;
  cout << "mode: " << statistics.get_mode() << endl;

  statistics.unique_set();

  cout << "UNIQUE SET PRINTING:";

  statistics.unique_Print();

  cout << endl;

  cout << "LENGTH OF UNIQUE SET: " << statistics.unique_length() << endl;

}
