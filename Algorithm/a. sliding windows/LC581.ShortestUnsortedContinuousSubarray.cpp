class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {

        int p1=0,p2=nums.size()-1,i;

        while(p1 < nums.size()-1 && nums[p1] <= nums[p1+1] )
        {
            p1++;
        }
        if (p1 == nums.size() - 1) 
        {  // if the array is sorted
            return 0;
        }

        while(p2 >0 && nums[p2] >= nums[p2-1] )
        {
            p2--;
        }

        

        int max=numeric_limits<int>::min(),min=numeric_limits<int>::max ();
        for(i=p1;i<=p2;i++)
        {
            if(nums[i] > max)
                max = nums[i];
            if(nums[i] < min)
                min = nums[i];
        }

        while(p1>0 && nums[p1-1] > min)
            p1--;
        
        while(p2<nums.size()-1 && nums[p2+1] < max)
            p2++;

        return p2-p1+1;

        }
        
    
};
