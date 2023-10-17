class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>arr1;
        vector<int>arr2;

        for(auto num:nums){
            if(num>0){
                arr1.push_back(num);
            }else{
                arr2.push_back(num);
            }
        }

        int p=0,n=0,i=0;

        while(i<nums.size() && p<arr1.size() && n<arr2.size()){
            if(i%2==0){
                nums[i]=arr1[p];
                p++;
            }else{
                nums[i]=arr2[n];
                n++;
            }
            i++;
        }

        while(p<arr1.size() && i<nums.size()){
            nums[i]=arr1[p];
            p++;
            i++;
        }

        while(n<arr2.size() && i<nums.size()){
            nums[i]=arr2[n];
            n++;
            i++;
        }

        return nums;
    
    }
};