// Nazmul Dewan
// CSCI 335
// Project 2
// This contains the implementation of listMedian function

#include "myList.hpp"

void listMedian(const std::vector<int> *instructions) {
  // const auto t1_start = chrono::steady_clock::now();

  // Create a list
  list<int> sortedlist;
  // Create a vector to store the medians
  vector<int> medianvector;
  // Iterates through the parameter
  for (auto it = instructions->begin(); it != instructions->end(); it++) {

    // If it is a pop instruction
    if (*it == -1) {

      // Checks if the list is even
      if (sortedlist.size() % 2 == 0) {
        //Goes to the position one less than the median
        auto lower = sortedlist.begin();
        advance(lower, sortedlist.size() / 2 - 1);

        //Goes to the position of the median
        auto upper = sortedlist.begin();
        advance(upper, sortedlist.size() / 2);

        // Compares if the lower is less than or equal to the upper
        if (*lower <= *upper) {
          // Adds it to the vector
          medianvector.push_back(*lower);
          // Removes it from the list
          sortedlist.erase(lower);
        }
      } 
      // Checks if the list is odd
      else if (sortedlist.size() % 2 == 1) {
        //Goes to the position one less than the median
        auto lower = sortedlist.begin();
        advance(lower, sortedlist.size() / 2 - 1);

        //Goes to the position of the median
        auto upper = sortedlist.begin();
        advance(upper, sortedlist.size() / 2);

        //Adds it to the vector
        medianvector.push_back(*upper);
        //Removes it from the list
        sortedlist.erase(upper);
      }

    } 
    // If it is not a pop instruction
    else if (*it != 1) {
      // Finds the position and inserts it into the list
      auto position = lower_bound(sortedlist.begin(), sortedlist.end(), *it);
      sortedlist.insert(position, *it);
    }
  }
  /* const auto t1_end = std::chrono::steady_clock::now();
   int t1 = chrono::duration<double, std::micro>(t1_end - t1_start).count();

   cout << "Execution Time Of List Median " << t1 << " Microseconds." << endl;*/
  // cout << "Median List: ";

  // Prints the medians from the median vector
  for (auto i = medianvector.begin(); i != medianvector.end(); i++) {
    cout << *i << " ";
    if (i == medianvector.end()) {
      cout << *i;
    }
  }
}
