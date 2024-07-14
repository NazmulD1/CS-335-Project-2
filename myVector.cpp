// Nazmul Dewan
// CSCI 335
// Project 2
// This contains the implementation of vectorMedian function

#include "myVector.hpp"


void vectorMedian(const std::vector<int> *instructions) {
  //const auto t1_start = chrono::steady_clock::now();

  //Sets a sortvector
  vector<int> sortedvector;

  //Sets a medianvector
  vector<int> medianvector;

  for (auto it = instructions->begin(); it != instructions->end(); it++) {

    // Checks if it is a pop instruction
    if (*it == -1) {
      // Checks if the vector is even
      if (sortedvector.size() % 2 == 0){
        // Compares the two middle values
        if(sortedvector[sortedvector.size() / 2-1] <= sortedvector[sortedvector.size() / 2]) {
          // Adds the lower of the 2 values to the vector
        medianvector.push_back(sortedvector[sortedvector.size() / 2 - 1]);
        // Removes it from the vector
        sortedvector.erase(sortedvector.begin() + sortedvector.size() / 2 - 1);
        }

      }
        //Checks if the vector is odd
      else if (sortedvector.size() % 2 == 1) {
        // Adds the middle value to the vector
  medianvector.push_back(sortedvector[sortedvector.size() / 2]);
        // Removes it from the vector
        sortedvector.erase(sortedvector.begin() + sortedvector.size() / 2);
      }
    }
      // If it is not a pop instruction
    else if (*it != 1) {
      // Adds the value to the vector
      auto position = lower_bound(sortedvector.begin(), sortedvector.end(), *it);
      sortedvector.insert(position, *it);
    } 
  }
    //const auto t1_end = std::chrono::steady_clock::now();
    //int t1 = chrono::duration<double, std::micro>(t1_end - t1_start).count();

    //cout << "Execution Time Of Vector Median " << t1 << " Microseconds." << endl;

  // Prints the medians from the median vector
  for (auto  i = medianvector.begin(); i != medianvector.end(); i++) {
    cout << *i << " ";
  }
}
