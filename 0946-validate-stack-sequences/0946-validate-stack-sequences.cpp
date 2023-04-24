class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int i=0,j=0;
        
        for(auto x:pushed)
        {
            st.push(x);
            while(st.size() && st.top()==popped[j])
            {
                st.pop();
                j++;
            }
        }
        
        return st.size()==0;
    }
};