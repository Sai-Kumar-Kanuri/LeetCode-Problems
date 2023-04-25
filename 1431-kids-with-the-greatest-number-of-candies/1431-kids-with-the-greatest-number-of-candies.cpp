class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        int maxCandies=0;
        for(auto candy:candies)
        {
            maxCandies=max(maxCandies,candy);
        }
        
        vector<bool>ans;
        
        for(auto candy:candies)
        {
            ans.push_back((candy+extraCandies)>=maxCandies);
        }
        
        return ans;
        
    }
};