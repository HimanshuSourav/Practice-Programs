/*
  Given an array of unsorted numbers and a target number, find all unique quadruplets in it, whose sum is equal to the target number.

Example 1:

Input: [4, 1, 2, -1, 1, -3], target=1
Output: [-3, -1, 1, 4], [-3, 1, 1, 2]
Explanation: Both the quadruplets add up to the target.
Example 2:

Input: [2, 0, -1, 1, -2, 2], target=2
Output: [-2, 0, 2, 2], [-1, 0, 1, 2]
Explanation: Both the quadruplets add up to the target.
  */
using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  static vector<vector<int>> searchQuadruplets(vector<int> &arr, int target) {
    vector<vector<int>> quadruplets;
    // TODO: Write your code here

    int left=0,right=arr.size()-1,i,j,targetsum;

    if(arr.size()<4)
    {
      return quadruplets;
    }
    
    sort(arr.begin(),arr.end());
    if(arr[0] > target)
      return quadruplets;

    for(i=0;i<arr.size()-4;i++)
    {
      if(i>0 && arr[i]==arr[i-1] )
        {
          continue;
        }
      for(j=i+1;j<arr.size()-3;j++)
      {
        if(j>i+1 && arr[j]==arr[j-1] )
        {
          continue;
        }
        left = j+1;
        if(arr[i] + arr[j] <= target)
        {
          targetsum = target - arr[i] - arr[j];
          vector<int> subarr;
          subarr.push_back(arr[i]);
          subarr.push_back(arr[j]);
          findpair(targetsum,arr,left,subarr,quadruplets);
        }
      }
    }
    return quadruplets;
  }

  static void findpair(int targetsum, vector<int> &arr,int left, vector<int> &subarr, vector<vector<int>> &quadruplets)
  {
    int right = arr.size()-1;
    while(left < right)
    {
      if(arr[left]+ arr[right] == targetsum)
      {
        subarr.push_back(arr[left]);
        subarr.push_back(arr[right]);
        quadruplets.push_back(subarr);
        break;
      }
      else if (arr[left]+ arr[right] < targetsum)
      {
        left++;
      }
      else
      {
        right--;
      }
    }


    return;
  }
};
