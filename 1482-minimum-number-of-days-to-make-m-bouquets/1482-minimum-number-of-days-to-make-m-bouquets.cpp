class Solution {
public:
    bool f(vector<int>& bloomDay, int day, int m, int k){
        int cnt=0;
        int noOfBouq = 0 ;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                cnt++;
            }else{
                noOfBouq += (cnt/k);
                cnt=0;
            }
        }
        
        noOfBouq += (cnt/k);
        
        return noOfBouq>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n = bloomDay.size();
        long long val = m * 1ll * k * 1ll;
        if(val > n){
            return -1;
        }
        
        int mini=INT_MAX;
        int maxi=INT_MIN;
        
        for(int i=0;i<n;i++){
            mini=min(mini,bloomDay[i]);
            maxi=max(maxi,bloomDay[i]);
        }
        
        int low = mini;
        int high= maxi;
        
        int ans=high;
        
        while(low<=high){
            
            int mid = (low+high)/2;
            
            if(f(bloomDay,mid,m,k)==true){
                ans=min(ans,mid);
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        
        return ans;
    }
};