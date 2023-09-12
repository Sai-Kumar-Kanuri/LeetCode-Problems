class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int>mp;
        
        unordered_set<int>st;
        int ans=0;
        
        for(auto ch : s){
            mp[ch]++;
        }
        
        for(auto it:mp){
            int freq=it.second;
            
            while(freq>0 && st.find(freq)!=st.end()){
                ans++;
                freq--;
            }
            
            st.insert(freq);
        }
        
        return ans;
    }
};