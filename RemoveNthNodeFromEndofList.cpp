/**
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]
**/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
            
        unsigned Count=1;// taking restrictions into account
        ListNode *Curr, *Prev;
        Curr = head;
                
        while(Curr->next !=NULL)
        {
            Curr = Curr->next;
            Count++;
        }
        
        if(Count != n)
        {
            Curr = head;
            for (unsigned int i = 0; (i < Count - n); i++)
            {
                Prev = Curr;
                Curr = Curr->next;
            }
            if( Prev !=NULL && Curr != NULL)
            {
                Prev->next = Curr->next;
            }          
            else
            {
                if(Curr == NULL)
                    Prev->next = NULL;
            }
        }
        else
        {
            //n == count means first element is to be deleted
            head= head->next;         
        }
        return head;
    }
    
};
