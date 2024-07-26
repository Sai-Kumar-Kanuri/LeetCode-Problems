class Solution {
    public void merge(int left,int mid,int right,int[] nums){

        int l = left;
        int r = mid+1;

        ArrayList<Integer> Ans = new ArrayList<>();
        while(l<=mid && r<=right){
            if(nums[l]<nums[r]){
                Ans.add(nums[l]);
                l++;
            }else{
                Ans.add(nums[r]);
                r++;
            }
        }

        while(l<=mid){
            Ans.add(nums[l]);
            l++;
        }

        while(r<=right){
            Ans.add(nums[r]);
            r++;
        }

        for (int i = left; i <= right; i++) {
            nums[i] = Ans.get(i - left);
        }


    }
    public void mergeSort(int left,int right,int[] nums){

        if(left>=right){
            return;
        }

        int mid = (left+right)/2;

        mergeSort(left,mid,nums);
        mergeSort(mid+1,right,nums);
        merge(left,mid,right,nums);

    }
    public int[] sortArray(int[] nums) {
        int n = nums.length;
        mergeSort(0,n-1,nums);

        return nums;
    }
}