#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)
#include<algorithm>

#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here
// helper function that preserves the longest and shortest paths
bool equalPathsHelper(Node* root, int len, int& min, int& max);

bool equalPaths(Node * root)
{
  // Add your code below
  if (root == nullptr) return true; 

  // declare default values for helper
  int maxLen = -1;
  int minLen = -1;    
  
  bool pathsAreEqual = equalPathsHelper(root, 0, minLen, maxLen);

  return pathsAreEqual && (maxLen == minLen);
}

bool equalPathsHelper(Node* root, int len, int& min, int& max) {
  if (root == nullptr) return true;

  if (root->left == nullptr && root->right == nullptr){
    if (max == -1 || len > max){
      max = len;
    }
    if (min == -1 || len < min){
      min = len;
    }
    return true;
  }

  bool left = equalPathsHelper(root->left, len+1, min, max);
  bool right = equalPathsHelper(root->right, len+1, min, max);

  return left && right;
}