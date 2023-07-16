class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>st;
        
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[i]<st.back() && n-i+st.size()>k){
                st.pop_back();
            }
            
            st.push_back(nums[i]);
        }
        
        
        vector<int>ans(st.begin(),st.begin()+k);
        return ans;
        
    }
};