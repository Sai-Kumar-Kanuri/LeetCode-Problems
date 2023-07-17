class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int>st;
        int count=0;
        int n=s.size();
        
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(s[i]);
            }else if (s[i] == ')') {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                } else {
                    count++;
                }
            }
        }
        int ans= count+st.size();
        return ans;
    }
};