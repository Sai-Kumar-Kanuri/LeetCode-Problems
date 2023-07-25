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
    ListNode* removeNodes(ListNode* head) {
        stack<int>st;

        ListNode* ptr = head;

        while(ptr){
            int val=ptr->val;
            while(!st.empty() && st.top()<val){
                st.pop();
            }
            st.push(val);
            ptr=ptr->next;
        }


        ListNode *root = NULL;
		while(!st.empty()){
			ListNode* temp = new ListNode;
		    temp->val= st.top();
		    temp->next = root;
		    root = temp;
			st.pop();
		}
		return root;
    }
};