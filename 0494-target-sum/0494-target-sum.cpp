
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int count=0;
        getCalculation(nums,target,0,0,count);
        return count;
    }
    void getCalculation(vector<int>&nums,int target,int sum,int i,int &count)
    {
        if(nums.size()==i){
            if(sum==target){
                count++;
            }
        }
        else{
            getCalculation(nums,target,sum+nums[i],i+1,count);
            getCalculation(nums,target,sum-nums[i],i+1,count);
        }
        
    }
};