class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        int n = num.size();
        
        for(auto ch : num){
            
            while(k>0 && !st.empty() && st.top()>ch){
                st.pop();
                k--;
            }
            st.push(ch);
        }
        
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }
        
        if(st.empty()){
            return "0";
        }
        
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        int leadingZeros = 0;
        while (leadingZeros < ans.size() && ans[leadingZeros] == '0') {
            leadingZeros++;
        }

        if (leadingZeros == ans.size()) {
            return "0";
        }

        return ans.substr(leadingZeros);

    }
};