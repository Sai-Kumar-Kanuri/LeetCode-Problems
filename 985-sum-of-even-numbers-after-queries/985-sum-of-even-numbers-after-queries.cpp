class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>sum_vector;
        int sum=0;
         for(auto x:nums)
            {  
                if(x%2==0)
                {
                    sum+=x;
                } 
            }
        for(auto &query:queries)
        {
            
            int old=nums[query[1]];
            int newele=old+query[0];
            if(old%2==0) sum-=old;
            if(newele%2==0) sum+=newele;
            nums[query[1]]=newele;
            sum_vector.push_back(sum);
        }
        return sum_vector;
    }
};