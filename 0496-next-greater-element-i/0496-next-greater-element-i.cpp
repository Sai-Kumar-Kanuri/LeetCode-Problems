class Solution {
public:
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int m=nums1.size();
        int n=nums2.size();
        unordered_map<int, int> nextGreaterMap;
        stack<int>st;
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums2[i]>=st.top()){
                st.pop();
            }
            
            if(!st.empty()){
                nextGreaterMap[nums2[i]]=st.top();
            }
            
            st.push(nums2[i]);
        }
        vector<int>ans;
        
        for (auto num : nums1) {
            if(nextGreaterMap.count(num) > 0) ans.push_back(nextGreaterMap[num]);
            else ans.push_back(-1);
        }
        
        return ans;
    }
};