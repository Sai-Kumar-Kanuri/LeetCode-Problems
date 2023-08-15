class Solution {
public:
    static bool compare( pair<string,int> a, pair<string,int> b){
        if(a.second==b.second){
            return a.first<b.first;
        }
        
        return a.second>b.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>mp;
        
        for(auto word : words){
            mp[word]++;
        }
        
        vector<pair<string,int>>arr(mp.begin(),mp.end());
        
        sort(arr.begin(),arr.end(),compare);
        vector<string>ans;
        for(int i=0;i<k;i++){
            ans.push_back(arr[i].first);
        }
        return ans;
    }
};