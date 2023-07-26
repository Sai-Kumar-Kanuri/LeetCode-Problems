class Solution {
public:
    double f(vector<int>&dist,int speed){
        
        double time = 0.0;
        
        for(int i=0;i<dist.size();i++){
            double t = (double) dist[i] / (double) speed;
            
            if(i==dist.size()-1){
                time+=t;
            }else{
                time+=ceil(t);
            }
        }
        
        return time;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left=0;
        int right = 1e7;
        
        int minSpeed=-1;
        
        while(left<=right){
            
            int mid = left + (right-left)/2;
            
            if(f(dist,mid)<=hour){
                minSpeed=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return minSpeed;
    }
};