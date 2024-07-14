// Nazmul Dewan
// CSCI 335
// Project 2
// This is the declaration of AVL Tree

#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std;

// Struct of the AVL Tree
struct AvlNode
{
  int element;
  AvlNode *left;    AvlNode *right;
  int height;

  AvlNode(const int &ele, AvlNode *lt, AvlNode *rt, int h = 0): element{ele}, left{lt}, right{rt}, height{h} {}

  AvlNode(int &&ele, AvlNode *lt, AvlNode *rt, int h = 0): element{std::move(ele)}, left{lt}, right{rt}, height{h} {}
};
// Gets the height of the tree
int height(AvlNode *t);

// Adds a node
void insert(const int &x, AvlNode *&t);

// Balances the tree
void balance(AvlNode *&t);

// Performs a left rotation
void rotateWithLeftChild(AvlNode *&k2);

// Performs a right rotation
void rotateWithRightChild(AvlNode *&k1);

// Performs a double left rotation
void doubleWithLeftChild(AvlNode *&k3);

// Performs a double right rotation
void doubleWithRightChild(AvlNode *&k1);
// Removes a node
void remove(const int &x, AvlNode *&t);
// Finds the min node
AvlNode *findMin(AvlNode *t);

// Finds the max node
AvlNode *findMax(AvlNode *t);

// Gets the median of the tree
void treeMedian(const std::vector<int> *instructions);