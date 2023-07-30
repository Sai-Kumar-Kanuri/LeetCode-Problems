class Solution {
public:
    int findMax(vector<int>& piles){
        int n=piles.size();
        
        int maxi=INT_MIN;
        
        for(int i=0;i<n;i++){
            maxi=max(maxi,piles[i]);
        }
        return maxi;
        
    }
    
    double findTotal(vector<int>&piles,int hourly){
        
        double maxi=0;
        
        for(auto pile:piles){
            maxi+=ceil((double)pile/(double)hourly);
        }
        
        return maxi;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=0;
        int high=findMax(piles);
        
        while(low<=high){
            
            int mid = low + (high - low) / 2;
            
            double totalHours = findTotal(piles,mid);
            
            if(totalHours>h){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        
        return low;
    }
};