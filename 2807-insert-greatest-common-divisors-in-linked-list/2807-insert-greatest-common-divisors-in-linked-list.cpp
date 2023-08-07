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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        
        ListNode* curr = head->next;
        ListNode* prev=head;
        
        while(curr){
            
            int val1 = curr->val;
            int val2 = prev->val;
            
            int n = __gcd(val1,val2);
            
            ListNode* node = new ListNode();
            
            node->val=n;
            prev->next=node;
            node->next=curr;
            
            prev=curr;
            curr=curr->next;
        }
        
        return head;
    }
};