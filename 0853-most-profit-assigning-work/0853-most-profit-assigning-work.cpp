class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>>mp;
        int n = profit.size();
        for(int i = 0;i<n;i++){
            mp.push_back({difficulty[i],profit[i]});
        }

        sort(mp.begin(),mp.end());

        int ans = 0;

        for(auto it1 : worker){
            int prof=0;
            for(auto it2 : mp){
                if(it1>=it2.first){
                    prof = max(prof,it2.second);
                }
            }
            ans+=prof;
        }
        
        return ans;
    }

   
};