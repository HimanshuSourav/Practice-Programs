/*
Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.

Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].

*/
class Solution {
public:
      
    vector<int> runningSum(vector<int>& nums) {
  
    /*n square*/  
    /*
        vector<int> sums(nums.size(),0);
        for(unsigned int i=0;i<nums.size();i++)
            for(unsigned int j=0;j<i+1;j++)   
                sums[i] = sums[i] + nums[j];
        return sums;
     */   
        
    /*n*/
        
        for(unsigned int i=1;i<nums.size();i++)
            nums[i]= nums[i]+nums[i-1];
        return nums;
    }
};
