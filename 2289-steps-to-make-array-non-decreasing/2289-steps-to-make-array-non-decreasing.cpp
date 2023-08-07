class Solution {
public:
    int totalSteps(vector<int>& nums) {
        stack<pair<int,int>>st;   //{index,count}
        int n=nums.size();
        int count=0;
        int ans=0;
        for(int i=n-1;i>=0;i--){
            count=0;
            while(!st.empty() && nums[i]>nums[st.top().first]){ 
                count=max(count+1,st.top().second);
                cout<<nums[i]<<" "<<count<<endl;
                st.pop();
            }
            ans=max(ans,count);
            st.push({i,count});
        }
        
        return ans;
    }
};