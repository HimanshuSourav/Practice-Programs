/*
457. Circular Array Loop

You are playing a game involving a circular array of non-zero integers nums. Each nums[i] denotes the number of indices forward/backward you must move if you are located at index i:

If nums[i] is positive, move nums[i] steps forward, and
If nums[i] is negative, move nums[i] steps backward.
Since the array is circular, you may assume that moving forward from the last element puts you on the first element, and moving backwards from the first element puts you on the last element.

A cycle in the array consists of a sequence of indices seq of length k where:

Following the movement rules above results in the repeating index sequence seq[0] -> seq[1] -> ... -> seq[k - 1] -> seq[0] -> ...
Every nums[seq[j]] is either all positive or all negative.
k > 1
Return true if there is a cycle in nums, or false otherwise.

  */
class Solution {
public:

    int findnextindex(int ptr,bool direction,const vector<int> &nums)
    {
        //change in direction
        if (direction != (nums[ptr] > 0))
            return -1;
        
        //wrap around for negative numbers.
        int next = (ptr+nums[ptr]+nums.size()) % nums.size();
        
        //self loop is not accepted loop
        if (next == ptr)
            return -1;
        
        return next;

    }

    bool circularArrayLoop(vector<int>& nums) {

        int slow,fast,i;
        bool direction;
        for(i=0;i<nums.size();i++)
        {
            slow=i;
            fast=i;
            direction = nums[i]>=0;
            do{
            
                slow = findnextindex(slow,direction,nums);
                fast = findnextindex(fast,direction,nums);
                if(fast !=-1)
                    fast = findnextindex(fast,direction,nums);
            }while(slow !=-1 && fast != -1 && slow != fast);

            if(slow != -1 && slow == fast)
                return true;
        }
        return false;
        
    }
};
