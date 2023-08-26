class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int>dp1(n+1,1);
        vector<int>dp2(n+1,1);
        int maxi=1;
        for(int i=1;i<n;i++){
            if(nums1[i-1]<=nums1[i]){
                dp1[i]=max(dp1[i],dp1[i-1]+1);
            }
            if(nums2[i-1]<=nums1[i]){
                dp1[i]=max(dp1[i],dp2[i-1]+1);
            }
            if(nums1[i-1]<=nums2[i]){
                dp2[i]=max(dp2[i],dp1[i-1]+1);
            }
            if(nums2[i-1]<=nums2[i]){
                dp2[i]=max(dp2[i],dp2[i-1]+1);
            }
            
            maxi = max({dp1[i],dp2[i],maxi});
        }
        
        return maxi;
    }
};