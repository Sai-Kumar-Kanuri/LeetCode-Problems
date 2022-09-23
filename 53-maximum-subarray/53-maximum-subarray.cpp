class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_so_far=INT_MIN,max_here=0;
        int s=0,start=0,end=0;
        
        for(int i=0;i<nums.size();i++)
        {
            max_here=max_here+nums[i];
            if(max_so_far<max_here)
            {
                max_so_far=max_here;
                start=s;
                end=i;
            }
            if(max_here<0){
                max_here=0;
                s=i+1;
            }
        }
        int sum=0;
        for(int i=start;i<end+1;i++)
        {
            sum+=nums[i];
        }
        return sum;
    }
    
};