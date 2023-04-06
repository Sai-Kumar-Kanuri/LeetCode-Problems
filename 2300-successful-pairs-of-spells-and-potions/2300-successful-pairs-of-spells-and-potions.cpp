class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        vector<int>ans(spells.size(),0);
        sort(potions.begin(),potions.end());
        
        for(int i=0;i<spells.size();i++)
        {
            int spell=spells[i];
            int count=0;
            int l=0,h=potions.size();
            while(l<h)
            {
                int mid=(l+h)/2;
                
                if(((long long)spell * (long long)potions[mid])>=success )
                {
                    h=mid;
                }
                else{
                    l=mid+1;
                }
            }
            ans[i]=potions.size()-l;
        }
        return ans;
        
    }
};