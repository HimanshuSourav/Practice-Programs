/*
Problem Statement
Given an array arr of unsorted numbers and a target sum, count all triplets in it such that arr[i] + arr[j] + arr[k] < target where i, j, and k are three different indices. Write a function to return the count of such triplets.

Example 1:

Input: [-1, 0, 2, 3], target=3 
Output: 2
Explanation: There are two triplets whose sum is less than the target: [-1, 0, 3], [-1, 0, 2]
Example 2:

Input: [-1, 4, 2, 1, 3], target=5 
Output: 4
Explanation: There are four triplets whose sum is less than the target: 
[-1, 1, 4], [-1, 1, 3], [-1, 1, 2], [-1, 2, 3]
*/

using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  static int searchTriplets(vector<int> &arr, int target) {
    int count = 0;
    int arrsum,i,left,right;

    sort(arr.begin(),arr.end());
    if(arr.size()<3)
      return 0;
    
    for(i=0;i<arr.size()-2;i++)
    {
      left =i+1;
      right = arr.size()-1;

      while(left<right)
      {
        arrsum = arr[i] + arr[left] + arr[right];
        printf("arr[%d]:%d arr[%d]:%d arr[%d]:%d\n arrsum:%d target:%d \n",i,arr[i],left,arr[left],right,arr[right],arrsum,target);
        if (arrsum< target)
        { 
          count+=(right-left); 
          left++;
        }
        else
        {
          right--;
        }
        
           
      }
    }
    
    return count;
  }
};
