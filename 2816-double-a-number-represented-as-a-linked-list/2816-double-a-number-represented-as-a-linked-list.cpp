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
    ListNode* doubleIt(ListNode* head) {
        vector<int>res;
        ListNode* node = head;
        
        while(node){
            res.push_back(node->val);
            node=node->next;
        }
        
        reverse(res.begin(),res.end());
        
        int carry=0;
        for(int i=0;i<res.size();i++){
            int num = res[i]*2+carry;
            carry=num/10;
            res[i]=num%10;
        }
        
        if(carry){
            res.push_back(carry);
        }
        
        reverse(res.begin(),res.end());
        
        ListNode* newNode = new ListNode(res[0]);
        ListNode* ptr = newNode;
        
        for(int i=1;i<res.size();i++){
            ptr->next=new ListNode(res[i]);
            ptr=ptr->next;
        }
        
        return newNode;
        
    }
};