class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        set<int>st;
        int ans=0;
        for(auto it:nums){
                st.insert(it);
        }
        int i=0;
        for(auto it:st){
            nums[i]=it;
            i++;
        }

        return st.size();
        
    }
};