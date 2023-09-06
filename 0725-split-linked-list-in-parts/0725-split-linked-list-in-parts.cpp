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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr = head;
        
        int N=0;
        
        while(curr!=nullptr){
            N++;
            curr=curr->next;
        }
        
        
        int size = N/k;
        int rem = N%k;
        vector<ListNode*>res;
        curr = head;
        
        for(int i=0;i<k;i++){
            res.push_back(curr);
            for(int j=0;j<size-1+(rem>0?1:0);j++){
                if(curr){
                    curr=curr->next;
                }
            }
            
            
            if(rem>0){
                rem--;
            }
            if(curr){
                ListNode* temp=curr->next;
                curr->next=nullptr;
                curr=temp;
            }
        }
        
        return res;
    }
};