class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int>st;
        vector<int>ans;
        int cnt=0;

        for(auto it : words){
            if(it=="prev"){
                cnt++;

                if(cnt>st.size()){
                    ans.push_back(-1);
                }else{
                    int n = st.size();
                    ans.push_back(st[n - cnt]);

                }
            }else{
                st.push_back(stoi(it));
                cnt=0;
            }
        }
        

        return ans;
    }
};