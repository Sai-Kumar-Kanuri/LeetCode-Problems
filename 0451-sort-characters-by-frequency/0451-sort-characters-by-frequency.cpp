class Solution {
public:
    string frequencySort(string s) {
        
        string ans = "";
        map<char,int>mp;

        for(auto it : s){
            mp[it]++;
        }


        vector<pair<int,char>>arr;

        for(auto it:mp){
            arr.push_back({it.second,it.first});
        }

        sort(arr.rbegin(),arr.rend());

        for(auto it: arr){
            int n = it.first;

            for(int i=0;i<n;i++){
                ans+=it.second;
            }
        }

        return ans;
    }
};