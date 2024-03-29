/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *p=head,*q=head;
        while(p && p->next)
        {
            q=q->next;
            p=p->next->next;
            
            if(p==q){
                return true;
            }
        }
        
        return false;
    }
};