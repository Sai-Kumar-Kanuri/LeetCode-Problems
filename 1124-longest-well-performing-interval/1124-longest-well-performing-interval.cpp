class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        unordered_map<int,int>mp;
        int sum=0;int ans;
        for(int i=0;i<n;i++){
            if(hours[i]>8){
                sum++;
            }else{
                sum--;
            }
            
            if(sum>0){
                ans=max(ans,i+1);
            }
            
            else if(mp.find(sum-1)!=mp.end()){
                ans=max(ans,i-mp[sum-1]);
            }
            
            if(mp.find(sum)==mp.end()){
                mp[sum]=i;
            }
        }        
        
        return ans;
        
    }
};