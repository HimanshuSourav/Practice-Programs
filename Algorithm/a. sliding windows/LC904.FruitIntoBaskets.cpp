/*
904. Fruit Into Baskets
Medium
4.4K
306
Companies
You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.
*/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int start=0,end=0,maxfruit=0;
        unordered_map<int,int> hm;
        for(end=0;end<fruits.size();end++)
        {
            hm[fruits[end]]++;
            while(hm.size()>2)
            {
                hm[fruits[start]]--;
                if(hm[fruits[start]]==0)
                    hm.erase(fruits[start]);
                start++;
            }
            maxfruit= max(maxfruit,end-start+1);
        }
        return maxfruit;
    }
};
