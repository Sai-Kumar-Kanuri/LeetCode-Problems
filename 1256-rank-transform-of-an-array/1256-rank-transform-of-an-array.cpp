class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        set<int>st;

        for(auto it:arr){
            st.insert(it);
        }

        unordered_map<int,int>mp;

        int x = 1;

        for(auto it:st){
            if(mp.find(it)==mp.end()){
                mp[it]=x;
                x++;
            }
        }


        vector<int>ans;

        for(auto it : arr){
            ans.push_back(mp[it]);
        }

        return ans;
        
    }
};