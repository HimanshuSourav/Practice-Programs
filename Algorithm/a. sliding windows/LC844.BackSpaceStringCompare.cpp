/*
844. Backspace String Compare
Easy

Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

 

Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
Example 3:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
 

Constraints:

1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.
  */


class Solution {
public:

    int findnextvalidindex(string s, int i)
    {
        int count =0;
        while(i >=0)
        {
            if(strncmp(&s[i],"#",1)==0)
            {
                count++;
            }
            else if(count > 0)
            {
                count--;
            }
            else
            {
                break;
            }
            i--;
        }
        return i;
    }
    bool backspaceCompare(string s, string t) {
        int p1,p2,i,j;
        p1 = s.size()-1;
        p2 = t.size()-1;

        if(p1 <0 || p2 <0)
            return false;
        
        while(p1 >= 0 || p2 >= 0)
        {
            i = findnextvalidindex(s, p1);
            j = findnextvalidindex(t, p2);
            if (i < 0 && j<0)
                return true;
            
            if(i <0 || j <0 || (s[i] != t[j]))
                return false;
            
            p1 = i-1;
            p2 = j-1; 
        }
        return true;

        }
    
};
