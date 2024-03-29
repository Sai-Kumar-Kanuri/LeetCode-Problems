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
    ListNode* reverseList(ListNode* head) {
        ListNode* ptr=head;
        ListNode* pre_ptr=nullptr;
        
        while(ptr){
            
            ListNode* temp = ptr->next;
            ptr->next=pre_ptr;
            pre_ptr=ptr;
            ptr=temp;
        }
        
        
        return pre_ptr;
    }
};