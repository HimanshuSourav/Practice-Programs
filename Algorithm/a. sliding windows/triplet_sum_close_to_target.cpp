/*
Problem Statement
Given an array of unsorted numbers and a target number, find a triplet in the array whose sum is as close to the target number as possible, return the sum of the triplet. If there are more than one such triplet, return the sum of the triplet with the smallest sum.

Example 1:

Input: [-1, 0, 2, 3], target=3 
Output: 2
Explanation: There are two triplets whose sum is less than the target: [-1, 0, 3], [-1, 0, 2]
Example 2:

Input: [-3, -1, 1, 2], target=1
Output: 0
Explanation: The triplet [-3, 1, 2] has the closest sum to the target.
Example 3:

Input: [1, 0, 1, 1], target=100
Output: 3
Explanation: The triplet [1, 1, 1] has the closest sum to the target.
Example 4:

Input: [0, 0, 1, 1, 2, 6], target=5
Output: 4
Explanation: There are two triplets with distance '1' from target: [1, 1, 2] & [0,0, 6]. Between these two triplets, the correct answer will be [1, 1, 2] as it has a sum '4' which is less than the sum of the other triplet which is '6'. This is because of the following requirement: 'If there are more than one such triplet, return the sum of the triplet with the smallest sum.'
  */

using namespace std;

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

class Solution {
public:
  static int searchTriplet(vector<int>& arr, int targetSum) {
   
    if(arr.size() < 3)
      return{};

    int currdiff,mindiff,arrsum,currsum;
    int i,left,right;
    sort(arr.begin(),arr.end());
    mindiff = INT_MAX;
    for(i=0;i<arr.size()-2;i++)
    {
      left  = i+1;
      right = arr.size()-1;
      while(left < right)
      {
        currsum  = arr[i]+arr[left]+arr[right];
        
        currdiff = targetSum - currsum;
        printf("arr[%d]:%d arr[%d]:%d arr[%d]:%d\n currsum:%d currdiff:%d mindiff:%d\n"
                    ,i,arr[i],left,arr[left],right,arr[right],currsum,currdiff,mindiff);
        if(currdiff == 0)
        {
          return currsum;
        }
        else if(abs(currdiff) < abs(mindiff)
              || abs(currdiff)== abs(mindiff) && currdiff>mindiff)
        {
          mindiff = currdiff;
          arrsum  = currsum;
        }
        if(currdiff>0)
        {
          left++;
        }
        else
        {
          right--;
        }

      }
    }
    return arrsum;
  }
};
