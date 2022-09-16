/*
Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.

Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11

*/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
     /*Bad Solution
       Runtime: 62 ms, faster than 14.42% 
       Memory Usage: 31.6 MB, less than 16.78%
     */
     
        /*
        vector<int> sums;
        unsigned int i;
        sums = nums;
        
        if(nums.size() <=1)
            return 0;
        
        for(i=1;i<sums.size();i++)
            sums[i]= sums[i] +sums[i-1];
            
        
               
        for(i=0;i<nums.size();i++)
            if(sums[i] -nums[i] == (sums[sums.size() -1] - sums[i] ))
                return i;
        
        return -1;
        */
        
        
        //Better Solution?
        //Runtime: 51 ms, faster than 29.45%
        //Memory Usage: 31.1 MB, less than 52.01%
        
        unsigned int Lsum=0,Rsum=0,i;
        
        for(i=0;i<nums.size();i++)
            Rsum += nums[i];
               
        for(i=0;i<nums.size();i++)
        {
            Lsum += nums[i];
            if(Lsum == Rsum)
                return i;
            Rsum -= nums[i]; 
        }        
        return -1;        
    }
};
