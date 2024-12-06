class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int count=0,sum=0;
        map<int,int>bmap;
        
        for(auto x : banned){
            bmap[x]++;
        }
        
        for(int i=1;i<=n;i++){
            if(bmap.find(i)==bmap.end() && (sum+i<=maxSum)){
                sum+=i;
                count++;
            }
        }
       
        return count;
        
    }
};