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
    int pairSum(ListNode* head) {
        ListNode* ptr=head;
        vector<int>val;
        while(ptr)
        {
            val.push_back(ptr->val);
            ptr=ptr->next;
        }
        
        int i=0;
        int j=val.size()-1;
        
        int max_sum=0;
        
        while(i<j)
        {
            max_sum=max(max_sum,val[i]+val[j]);
            i++;
            j--;
        }
        
        return max_sum;
        
    }
};