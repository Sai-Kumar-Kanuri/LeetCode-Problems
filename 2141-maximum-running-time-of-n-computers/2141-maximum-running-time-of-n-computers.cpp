class Solution {
public:
    long long f(vector<int>& batteries,long long time,int n){
        long long duration =0;
        
        for(auto battery:batteries){
            if(battery<time){
                duration+=battery;
            }else{
                duration+=time;
            }
        }
        
        
        return duration >= time*n;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long low=0,high=0;
        int m=batteries.size();
        
        for(int i=0;i<m;i++){
            high+=batteries[i];
        }
        
        long long ans=0;
        
        while(low<=high){
            long long mid = low + (high-low)/2;
            
            if(f(batteries,mid,n)){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        
        return ans;
    }
};