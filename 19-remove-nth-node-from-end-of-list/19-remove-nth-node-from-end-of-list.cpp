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
        
        ListNode* p;
        ListNode* q;
        if(head)
        {
             p=head;
        q=head;
        for(int i=0;i<n;i++)
        {
            p=p->next;
        }
            
            if(p==NULL)
            {
                head=head->next;
                return head;
            }
        
        while(p->next)
        {
            q=q->next;
            p=p->next;
        }
            
            if(q->next && q->next->next)
            {
                q->next=q->next->next;
            }
            else{
                q->next=NULL;
            }
        }
       return head;
    }
};