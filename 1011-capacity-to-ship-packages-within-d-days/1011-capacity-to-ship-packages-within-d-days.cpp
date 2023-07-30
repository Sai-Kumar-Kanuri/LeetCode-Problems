class Solution {
public:
    bool f(vector<int>& weights,int mid,int days){
        
        int totalDays=1;
        int sum=0;
        
        for(int i=0;i<weights.size();i++){
            
            if(sum+weights[i]>mid){
                totalDays++;
                sum=weights[i];
            }else{
                sum+=weights[i];
            }
        }
        
        return totalDays<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int n = weights.size();
        int low = *max_element(weights.begin(), weights.end());
        int high=0;
        
        for(int i=0;i<n;i++){
            high+=weights[i];
        
        }
        int ans=high;
        while(low<=high){
            
            int mid = (low+high)/2;
            
            if(f(weights,mid,days)){
                ans=min(ans,mid);
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};