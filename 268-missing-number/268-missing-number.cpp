class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int>set_num(nums.begin(),nums.end());
        int n=nums.size();
        int x;
        for(int i=0;i<=n;i++)
        {
            if(set_num.find(i)==set_num.end())
            {
                x=i;
                break;
            }
        }
        return x;
        
    }
};