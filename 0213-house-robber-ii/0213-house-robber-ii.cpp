class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp1,temp2;
        if(n==1){
            return nums[0];
        }
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
    long long int ans1=houserob(temp1);
    long long int ans2=houserob(temp2);
    return max(ans1,ans2);
        
    }
    long long int houserob(vector<int>& nums) {
        long long int prev=nums[0];
        long long int prev2=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
             long long int take=nums[i];
            if(i>1){
                take+=prev2;
            }
            long long int nottake=0+prev;
            long long int curri = max(take,nottake);
            prev2=prev;
            prev=curri;
        }
        return prev;
        
}
};