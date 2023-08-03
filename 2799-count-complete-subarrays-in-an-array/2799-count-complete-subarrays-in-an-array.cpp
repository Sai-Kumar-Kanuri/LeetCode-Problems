class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        
        unordered_set<int>st(nums.begin(),nums.end());
        
        int n = nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_set<int>temp;
            for(int j=i;j<n;j++){
                temp.insert(nums[j]);
                if(st.size()==temp.size()){
                    ans++;  
                }
            }
        }
        return ans;
    }
};