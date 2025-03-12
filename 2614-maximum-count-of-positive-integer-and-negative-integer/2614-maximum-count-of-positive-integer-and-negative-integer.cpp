class Solution {
public:
    int maximumCount(vector<int>& nums) {
        
        int posi=0;
        int neg = 0;

        for(auto it : nums){
            if(it>0){
                posi++;
            }else if(it<0){
                neg++;
            }
        }

        return max(posi,neg);
    }
};