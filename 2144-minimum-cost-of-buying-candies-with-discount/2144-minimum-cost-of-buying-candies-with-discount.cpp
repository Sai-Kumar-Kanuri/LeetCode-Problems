class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(),cost.rend());
        
        int n=cost.size();
        
        int sum=0;
        int i=0;
        while(i<n){
            if(i!=n-1){
            sum+= cost[i]+cost[i+1];
            }
            else{
                sum+=cost[i];
            }
            i=i+3;
        }
        return sum;
    }
};