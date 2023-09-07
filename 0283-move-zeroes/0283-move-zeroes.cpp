class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                nums[k]=nums[i];
                k++;
            }
        }
        
        for(int i=k;k<n;k++){
            nums[k]=0;
        }
        
    }
};