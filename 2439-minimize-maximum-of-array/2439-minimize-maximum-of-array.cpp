class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        
        long long int totalSum = 0; // Use 'long long int' for totalSum
        int n=0;
        int ans=nums[0];
        for(auto num:nums){
            totalSum+=num;
            n++;
            int temp=(totalSum+n-1)/n;
            ans=max(ans,temp);
        }
        return ans;
    }
};