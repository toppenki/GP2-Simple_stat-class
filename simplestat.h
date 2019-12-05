#ifndef SIMPLESTAT_H
#define SIMPLESTAT_H

//header files needed
#include "llink.h"

#include <utility> // for pair
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

    LList<I> stat_values;

    int input_size = 0; // gets the size of the input/total amt of input values

    std::vector uniq_value_check; 
    /* the vector that checks the number of occurances for a value
    increments by one if the value is found
    */

    //calculating functions
    void find_mode(I numberSet) {



    }

    void find_median(I numberSet) {

        

    }

    void find_mean(I numberSet) {

        for (int i = 0; i < input_size; i++) {

            mean += numberSet[i];

        }

        mean /= input_size;

    }

    void find_SD(I numberSet) {

    }

    void find_min(I numberSet) {

        for (int i = 0; i < input_size; i++) {
            
            if (numberSet[i] < max_val) {
                min_val = numberSet[i];
            }

        }

    }

    void find_max(I numberSet) {

        for (int i = 0; i < input_size; i++) {
            
            if (numberSet[i] > max_val) {
                max_val = numberSet[i];
            }

        }

    }

    void update(I numberSet) { // updates the values of each variable

        find_max(numberSet);
        find_mean(numberSet);
        find_median(numberSet);
        find_min(numberSet);
        find_mode(numberSet);
        find_SD(numberSet);

    }

    public:
    //constructor
    Simple_stat(I data_values) {

        update(data_values);

        //appends values of array
        stat_values.append(max_val);
        stat_values.append(min_val);
        stat_values.append(mode);
        stat_values.append(median);
        stat_values.append(mean);
        stat_values.append(std_dev);

    }
    //destructor
    ~Simple_stat() {
        stat_values.removeall(); //emptys linked list
    }

    //member functions
    std::pair<I,I> search(I list_provided, I searchKey) {

        bool first_instance = false; //detects if first occurance has been found

        T initial_occurance = 0; // stores index of initial occurance of searchKey
        T num_occurances = 0; // # of times the searchKey occurs

        std::pair<T,T> first_and_occurances; // stores occurances and first instance of key

        // insert search method 

        first_and_occurances = std::make_pair(initial_occurance, num_occurances);

        return first_and_occurances;
    }


    //getters
    I get_mode() { return mode; }
    I get_median() { return median; }
    I get_mean() { return mean; }
    I get_SD() { return std_dev; }
    I get_min() { return min_val; }
    I get_max() { return max_val; }



};

#endif
