class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt=0;
        int n = nums.size();
        map<int,int>mp;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            
            if(sum==k){
                cnt++;
            }
            
            int rem=sum-k;
            if(mp.find(rem)!=mp.end()){
                cnt+=mp[rem];
            }
            
            // if(mp.find(sum)==mp.end()){
            //     mp[sum]=i;
            // }
            mp[sum]++;
        }
        
        return cnt;
    }
};