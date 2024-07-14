// Nazmul Dewan
// CSCI 335
// Project 2
// This is the implementation of heapMedian function

#include "myHeap.hpp"

void heapMedian(const std::vector<int> *instructions) {
  // const auto t1_start = chrono::steady_clock::now();
  
  // Sets max heap
  priority_queue<int> maxheap;
  
  // Sets min heap
  priority_queue<int, vector<int>, greater<int>> minheap;

  // Sets vector to store median
  vector<int> medianvector;

  for (auto it = instructions->begin(); it != instructions->end(); it++) {

    // If it is not a pop instruction and the maxheap is empty
    if (*it != -1 && maxheap.empty()) {
      // Adds it to the maxheap
      maxheap.push(*it);
    }

    // If it is a pop instruction
    else if (*it == -1) {
      // Adds the value to the vector
      medianvector.push_back(maxheap.top());
      //Removes from the max heap
      maxheap.pop();

      //Checks if the min heap size is greater than the max heap size
      if (minheap.size() > maxheap.size()) {
        // Adds the value to the max heap
        maxheap.push(minheap.top());
        // Removes the value from the min heap
        minheap.pop();
      }
    }

    else {
      // Checks if the value is greater than the maxheap top
      if (*it > maxheap.top()) {
        // Adds the value to the min heap
        minheap.push(*it);
        // Checks if the min heap size is greater than the max heap size
        if (minheap.size() > maxheap.size()) {
          // Adds the value to the max heap
          maxheap.push(minheap.top());
          // Removes the value from the min heap
          minheap.pop();
        }
      } else {
        // Adds the value to the max heap
        maxheap.push(*it);
        // Checks if the min heap size is greater than the max heap size
        if (maxheap.size() > minheap.size() + 1) {
          // Adds the value to the min heap
          minheap.push(maxheap.top());
          // Removes the value from the max heap
          maxheap.pop();
        }
      }
    }
  }
  /* const auto t1_end = std::chrono::steady_clock::now();
   int t1 = chrono::duration<double, std::micro>(t1_end - t1_start).count();

   cout << "Execution Time Of Heap Median " << t1 << " Microseconds." << endl;*/
  // cout << "Median Heap: ";
  
  // Prints the medians from the median vector
  for (auto i = medianvector.begin(); i != medianvector.end(); i++) {
    cout << *i << " ";
    if (i == medianvector.end()) {
      cout << *i;
    }
  }
}