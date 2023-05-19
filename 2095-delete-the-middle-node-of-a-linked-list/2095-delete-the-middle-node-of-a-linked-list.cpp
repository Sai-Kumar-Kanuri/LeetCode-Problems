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
    ListNode* deleteMiddle(ListNode* head) {
        
        if (!head -> next) return nullptr;
        
        int count=0;
        
        ListNode* p1=head;
        ListNode* p2=head;
        
        
        while(p1)
        {
            p1=p1->next;
            count++;
        }
        
        int mid=count/2;
            
            for(int i=0;i<mid-1;i++)
            {
                p2=p2->next;
            }
        
        
        p2->next=p2->next->next;
        
        return head;
    }
};