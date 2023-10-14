class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        
        int ans = n;
        
        set<int>st(nums.begin(),nums.end());
        
        vector<int>arr(st.begin(),st.end());
        
        int j=0;
        for(int i=0;i<n;i++){
            while(j<arr.size() && arr[j]<arr[i]+n){
                j++;
            }
            
            int window = j-i;
            ans=min(n-window,ans);
        }
        
        return ans;
    }
};