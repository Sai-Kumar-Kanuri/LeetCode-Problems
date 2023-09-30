class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        stack<int>st;
        int n=nums.size();
        int maxi =INT_MIN;
        
        for(int i=n-1;i>=0;i--){
            if(nums[i]<maxi){
                return true;
            }
            
            while(!st.empty() && st.top()<nums[i]){
                maxi=st.top();
                st.pop();
            }
            
            st.push(nums[i]);
        }
        
        return false;
        
    }
};