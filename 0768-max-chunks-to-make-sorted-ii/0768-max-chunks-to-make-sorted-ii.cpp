class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int>st;
        
        int n=arr.size();
        for(int i=0;i<n;i++){
            int maxi=arr[i];
            while(!st.empty() && st.top()>arr[i]){
                maxi=max(maxi,st.top());
                st.pop();
            }
            
            st.push(maxi);
        }
        
        return st.size();
    }
};