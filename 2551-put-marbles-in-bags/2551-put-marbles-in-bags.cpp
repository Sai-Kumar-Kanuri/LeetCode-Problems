class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        
        vector<long long> pairs;
        
        for(int i=1;i<weights.size();i++){
            pairs.push_back(weights[i]+weights[i-1]);
        }
        
        sort(pairs.begin(),pairs.end());
        
        int n=pairs.size();
        long long mini=0;
        for(int i=0;i<k-1;i++){
            mini+= pairs[i];
        }

        long long maxi=0;
        for(int i=0;i<k-1;i++){
            maxi+= pairs[n-1-i];
        }
        return maxi - mini;
    }
};