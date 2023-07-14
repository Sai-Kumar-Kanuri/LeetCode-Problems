class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int>mp;
        int ans=1;
        for(auto it:arr){
            
            if(mp.count(it-difference)){
                mp[it]=mp[it-difference]+1;
            }
            else{
                mp[it]=1;
            }
            ans=max(ans,mp[it]);
        }
        
        return ans;
    }
};