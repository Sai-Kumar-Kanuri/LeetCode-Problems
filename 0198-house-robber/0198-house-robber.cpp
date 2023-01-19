class Solution {
public:
    int rob(vector<int>& nums) {
        int prev=nums[0];
        int prev2=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
             int take=nums[i];
            if(i>1){
                take+=prev2;
            }
            int nottake=0+prev;
            int curri = max(take,nottake);
            prev2=prev;
            prev=curri;
        }
        return prev;
        
    }
};