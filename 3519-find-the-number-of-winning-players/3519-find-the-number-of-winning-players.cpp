class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        

        unordered_map<int,unordered_map<int,int>>mp;

        for(auto it:pick){
            mp[it[0]][it[1]]++;
        }

        int ans = 0;

        for(int i=0;i<n;i++){
            for(auto it : mp[i]){
                if(it.second>i){
                    ans++;
                    break;
                }
            }
        }

        return ans;
    }
};