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
    ListNode* partition(ListNode* head, int x) {
        
        if (head == NULL) return head;
        
        ListNode* arr1=NULL;
        ListNode* arr2=NULL;
        
        ListNode* temp1=NULL;
        ListNode* temp2=NULL;

        
        while(head){
            if(head->val<x){
                if(arr1==NULL){
                    arr1=head;
                    temp1=arr1;
                }else{
                    temp1->next=head;
                    temp1=temp1->next;
                }
            }else{
                if(arr2==NULL){
                    arr2=head;
                    temp2=arr2;
                }else{
                    temp2->next=head;
                    temp2=temp2->next;
                }
            }
            
            head=head->next;
        }
        
        if(temp2) temp2->next=NULL;
        
        if(temp1){
            temp1->next=arr2;
        }else{
            return arr2;
        }
        
        
        return arr1;
    }
};