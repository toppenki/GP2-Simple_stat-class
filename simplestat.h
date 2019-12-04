#ifndef SIMPLESTAT_H
#define SIMPLESTAT_H

#include <iostream>

template <typename I>
class Simple_stat {

private:
I max_val = 0; //maximum
I min_val = 0; //minimum
I mode = 0; //most repeated #
I median = 0; //middle value
I mean = 0; //avg
I std_dev = 0; //standard deviation

int length = 0; 
/*to count the length of the input type
ie: length of input is 10, length becomes 10*/
 
int mode_array[length]; 
/* maybe have an array of some sort to count the number of each
unique number, and then increase the value + 1 everytime that value is found
meaning every thing is set to 0*/

//calculating functions
I find_mode() {

}

I find_median() {

}

I find_mean() {

}

I find_SD() {

}

I find_min() {

}

I find_max() {

}


public:
//NEED CONSTRUCTOR
//NEED DESTRUCTOR
  
//getters
I get_mode() { return mode; }
I get_median() { return median; }
I get_mean() { return mean; }
I get_SD() { return std_dev; }
I get_min { return min_val; }
I get_max { return max_val; }



};

#endif
