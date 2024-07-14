// Nazmul Dewan
// CSCI 335
// Project 2
// This is the implementation of AVL Tree and median
// AVL Implementations Source: https://users.cs.fiu.edu/~weiss/dsaa_c++4/code/AvlTree.h
#include "myAVLtree.hpp"

int height(AvlNode *t) {
  if (t == nullptr) {
    return -1;
  } else {
    return t->height;
  }
}

void insert(const int &x, AvlNode *&t) {
  if (t == nullptr) {
    t = new AvlNode{x, nullptr, nullptr};
  } else if (x <= t->element)
    insert(x, t->left);
  else if (t->element <= x)
    insert(x, t->right);
  balance(t);
}

static const int ALLOWED_IMBALANCE = 1;
void balance(AvlNode *&t) {
  if (t == nullptr)
    return;

  if (height(t->left) - height(t->right) > ALLOWED_IMBALANCE)
    if (height(t->left->left) >= height(t->left->right))
      rotateWithLeftChild(t);
    else
      doubleWithLeftChild(t);
  else if (height(t->right) - height(t->left) > ALLOWED_IMBALANCE)
    if (height(t->right->right) >= height(t->right->left))
      rotateWithRightChild(t);
    else {
      doubleWithRightChild(t);
    }
  t->height = max(height(t->left), height(t->right)) + 1;
}

void rotateWithLeftChild(AvlNode *&k2) {
  AvlNode *k1 = k2->left;
  k2->left = k1->right;
  k1->right = k2;
  k2->height = max(height(k2->left), height(k2->right)) + 1;
  k1->height = max(height(k1->left), k2->height) + 1;
  k2 = k1;
}

void rotateWithRightChild(AvlNode *&k1) {
  AvlNode *k2 = k1->right;
  k1->right = k2->left;
  k2->left = k1;
  k1->height = max(height(k1->left), height(k1->right)) + 1;
  k2->height = max(height(k2->right), k1->height) + 1;
  k1 = k2;
}

void doubleWithLeftChild(AvlNode *&k3) {
  rotateWithRightChild(k3->left);
  rotateWithLeftChild(k3);
}

void doubleWithRightChild(AvlNode *&k1) {
  rotateWithLeftChild(k1->right);
  rotateWithRightChild(k1);
}

void remove(const int &x, AvlNode *&t) {
  if (t == nullptr)
    return; // Item not found; do nothing

  if (x < t->element)
    remove(x, t->left);
  else if (t->element < x)
    remove(x, t->right);
  else if (t->left != nullptr && t->right != nullptr) // Two children
  {
    t->element = findMin(t->right)->element;
    remove(t->element, t->right);
  } else {
    AvlNode *oldNode = t;
    t = (t->left != nullptr) ? t->left : t->right;
    delete oldNode;
  }

  balance(t);
}

AvlNode *findMin(AvlNode *t) {
  if (t == nullptr)
    return nullptr;
  while (t->left != nullptr)
    t = t->left;
  return t;
}


AvlNode *findMax(AvlNode *t) {
    if (t == nullptr)
        return nullptr;
    while (t->right != nullptr)
        t = t->right;
    return t;
}

void treeMedian(const std::vector<int> *instructions) {
  // Create an AVL tree
  AvlNode *max = nullptr;
  AvlNode *min = nullptr;
  // Creates a vector for median
  vector <int> medianvector;
  // Create counters
  int maxcounter = 0;
  int mincounter = 0;
  // Iterates through the parameter
  for (auto it = instructions->begin(); it != instructions->end(); it++) {
    // If the value is negative and it max is empty
    if (max == nullptr && *it != -1){
      // Insert the value into the max tree
      insert(*it, max);
      // Increment max counter
      maxcounter ++;
    }
    else if(*it == -1){
      // Adds the maximum value of the max avl tree to the vector
      medianvector.push_back(findMax(max)->element);
      // Removes the maximum value of the max avl tree
      remove(findMax(max)->element, max);
      // Decrement max counter
      maxcounter --;
      // If the min counter is greater than max counter 
      if (mincounter > maxcounter){
        //Insert the minimum value of the min avl tree to the max avl tree
        insert(findMin(min)->element, max);
        // Remove the minimum value of the min avl tree
        remove(findMin(min)->element, min);
        // Increment max counter
        maxcounter ++;
        // Decrement min counter
        mincounter --;
        
      }
      
    }
    else{
      // Checks if the value is less than or equal to maximum value of the max avl tree
      if(*it <= findMax(max)->element){
        // Insert the value into the max avl tree
        insert(*it, max);
        // Increment max counter
        maxcounter ++;

        // If the min counter is greater than max counter
        if (maxcounter > mincounter +1){
          // Insert the minimum value of the min avl tree to the max avl tree
          insert(findMax(max)->element, min);
          // Remove the maximum value of the max avl tree
          remove(findMax(max)->element, max);
          // Decrement max counter
          maxcounter --;
          // Increment min counter
          mincounter ++;
        }
      }
      else if( *it > findMax(max)->element){
        insert(*it, min);
        // Increment min counter
        mincounter++;
        // If the max counter is greater than min counter
        if (mincounter > maxcounter){
          // Insert the maximum value of the max avl tree to the min avl tree
          insert(findMin(min)->element, max);
          // Remove the minimum value of the min avl tree
          remove(findMin(min)->element, min);
          // Increment max counter
          maxcounter ++;
          // Increment min counter
          mincounter --;
          
        }
      }
    }
  }
  // Delete the max tree
  delete max;
  max = nullptr;
  
  // Delete the min tree
  delete min;
  min = nullptr;

  // Prints the median values
  for (auto i = medianvector.begin(); i != medianvector.end(); i++) {
    cout << *i << " ";
    if (i == medianvector.end()) {
      cout << *i;
    }
  }
}