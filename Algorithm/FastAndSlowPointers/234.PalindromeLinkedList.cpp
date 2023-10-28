/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *mid, *p1;
        std::stack<int> mystack;

        mid =head;
        p1 = head;

        while(p1 !=NULL && p1->next != NULL)
        {
            mystack.push(mid->val);
            mid = mid->next;
            p1  = p1->next->next;
        }

         if (p1 != nullptr)
            mid = mid->next;
            
        while(mid != NULL && !mystack.empty())
        {
            if(mystack.top() != mid->val)
                return false;
            else
            {
                mid = mid->next;
                mystack.pop();
            }
        }

        return true;


        
    }
};
