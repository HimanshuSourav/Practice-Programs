/*
Problem Statement
Given an array containing 0s, 1s and 2s, sort the array in-place. You should treat numbers of the array as objects, hence, we can’t count 0s, 1s, and 2s to recreate the array.

The flag of the Netherlands consists of three colors: red, white and blue; and since our input array also consists of three different numbers that is why it is called Dutch National Flag problem.

Example 1:

Input: [1, 0, 2, 1, 0]
Output: [0 0 1 1 2]
Example 2:

Input: [2, 2, 0, 1, 2, 0]
Output: [0 0 1 2 2 2 ]
*/


using namespace std;

#include <iostream>
#include <vector>

class Solution {
public:
  static void myswap(int &a, int &b)
  {
      a= a ^ b;
      b= a ^ b;
      a= a ^ b;
      return;
  }
  static vector<int> sort(vector<int> &arr) {
    int left=0,right= arr.size()-1,curr;

    for(curr=0;curr<=right;)
    {
        if(arr[curr]==0)
        {
          myswap(arr[left],arr[curr]);
          left++;
          curr++;
        }
        else if(arr[curr]==2)
        {
          swap(arr[curr], arr[right]);
          right--;
        }
        else
        {
          curr++;
        }
      }
    
    return arr;
  }
};
