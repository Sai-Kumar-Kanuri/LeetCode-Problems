class Solution {
public:
    int findMin(vector<int>& arr) {
        int start=0;
        int end= arr.size()-1;
        
        while(start<end)
        {
            int mid=start+(end-start)/2;
            
            // if(mid<end && arr[mid]>arr[mid+1])
            // {
            //     return arr[mid+1];
            // }
            // else if(mid>start && arr[mid]<arr[start])
            // {
            //     return arr[mid];
            // }
            if(arr[mid]<arr[end])
            {
                end=mid;
            }
            else {
                start=mid+1;
            }
        }
        
        return arr[start];
    }
};