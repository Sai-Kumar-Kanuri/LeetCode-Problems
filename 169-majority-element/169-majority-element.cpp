class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>umap;
        for(auto x:nums)
        {
            umap[x]+=1;
        }
        int max=(nums.size())/2,n=0;
        for(auto x:umap)
        {
            if(x.second>=max)
            {
                n=x.first;
                max=x.second;
            }
        }
        return n;
    }
};