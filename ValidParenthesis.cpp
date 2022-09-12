/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type

Constraints:
1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

*/
#include <stack>
class Solution {
public:
    bool isStartingBracket(char ch)
    {
        if(
           ch == '(' ||
           ch == '{' ||
           ch == '[' 
          ) return true;
        else
            return false;
    }

    bool isStackTopMatch(char A, char B)
    {
        if(
           A == '(' && B == ')'  ||
           A == '{' && B == '}'   ||
           A == '[' && B == ']'
          ) return true;
        else
            return false;
    }

    bool isValid(string s) 
    {
        string:: iterator it;
        stack<char> st;

        for(it = s.begin(); it!= s.end(); it++)
        {
            if(isStartingBracket(*it))
            {
                st.push(*it);
            }
            else if(!st.empty())
            {
                if( isStackTopMatch(st.top(),*it) )
                    st.pop(); 
                else
                    return false;
            }
            else
            {
                return false;
            }
        }
        
        if(st.empty())
            return true;
        else
            return false;
        
    }
};
