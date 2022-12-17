class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double mean;
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        sort(nums1.begin(),nums1.end());
        int n=nums1.size();
        if(n%2==0)
        {
            cout<<nums1[n/2]<<endl;
            cout<<nums1[(n/2)-1];
            mean=(double(nums1[n/2]+nums1[(n/2)-1]))/2;
        }
        else
        {
            mean=nums1[(n/2)];
        }
        return mean;
    }
};