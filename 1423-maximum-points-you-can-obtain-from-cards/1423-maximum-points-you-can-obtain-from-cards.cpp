class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0,ans=0;
        int n=cardPoints.size();
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        
        ans=sum;
        for(int i=k-1;i>=0;i--){
            sum-=cardPoints[i];
            sum+=cardPoints[n-k+i];
            ans=max(ans,sum);
        }
        
        return ans;
    }
};