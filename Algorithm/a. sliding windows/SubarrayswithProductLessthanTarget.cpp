/*
Problem Statement
Given an array with positive numbers and a positive target number, find all of its contiguous subarrays whose product is less than the target number.

Example 1:

Input: [2, 5, 3, 10], target=30                                              
Output: [2], [5], [2, 5], [3], [5, 3], [10]                           
Explanation: There are six contiguous subarrays whose product is less than the target.
Example 2:

Input: [8, 2, 6, 5], target=50                                              
Output: [8], [2], [8, 2], [6], [2, 6], [5], [6, 5]                         
Explanation: There are seven contiguous subarrays whose product is less than the target.
  */


using namespace std;

#include <deque>
#include <iostream>
#include <vector>

class Solution {
public:
  static vector<vector<int>> findSubarrays(const vector<int>& arr, int target) {
    vector<vector<int>> result;

    int product=1,left=0,right,i;

    for(right=0;right<arr.size();right++)
    {
      product *=arr[right];

      while(product>=target && left<arr.size())
      {
        product /=arr[left];
        left++;
      }

        deque<int> templist;
        for(i=right;i>=left;i--)
        {
          templist.push_front(arr[i]);
          vector<int> subarr;

          std::move(std::begin(templist),std::end(templist),std::back_inserter(subarr));
          result.push_back(subarr);
          
        }
    }

    return result;
  }
};
