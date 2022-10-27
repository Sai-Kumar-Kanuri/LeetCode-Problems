/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    
//     int findPeakIndex(MountainArray &mountainArr)
//     {
//         int start=0;
//         int end=mountainArr.length();
        
//         while(start<end)
//         {
//             int mid=start+(end-start)/2;
            
//             if(mountainArr.get(mid)>mountainArr.get(mid+1))
//             {
//                 end=mid;
//             }
//             // else if(target>mountainArr.get(mid)){
//             //     start=mid+1;
//             // }
//             else{
//                 start=mid+1;
//             }
//         }
//         return start;
//     }
//     int binarySearch(int target, MountainArray &mountainArr,int start,int end)
//     {
//         // int start=0;
//         // int end=findPeakIndex(mountainArr);
        
//         bool isAsc = mountainArr.get(start)<mountainArr.get(end);
        
//         while(start<=end)
//         {
//             int mid=start+(end-start)/2;
            
//             if(target==mountainArr.get(mid))
//             {
//                 return mid;
//             }
            
//             if(isAsc)
//             {
//                 if(target<mountainArr.get(mid))
//                 {
//                     end=mid-1;
//                 }
//                 else{
//                     start=mid+1;
//                 }
//             }
//             else{
//                 if(target>mountainArr.get(mid))
//                 {
//                     end=mid-1;
//                 }
//                 else{
//                     start=mid+1;
//                 }
//             }
            

//             // else{
//             //     return mid;
//             // }
//         }
//         return -1;
//     }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        // int start=0;
        // int peak=findPeakIndex(mountainArr);
        // int end=mountainArr.length();
        // int firstsearch=binarySearch(target,mountainArr,start,peak);
        // if(firstsearch != -1)
        // {
        //     return firstsearch;
        // }
        //     return binarySearch(target,mountainArr,peak+1,end);
         int n = mountainArr.length(), l = 0, r = n - 1, mid, peak_pos;
    // Find peak position
    while (l < r) {
        mid = l + (r - l) / 2;
        if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
            l = peak_pos = mid + 1;
        } else {
            r = mid;
        }
    }
    // Find left part
    l = 0;
    r = peak_pos;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (mountainArr.get(mid) < target) {
            l = mid + 1;
        } else if (mountainArr.get(mid) > target) {
            r = mid - 1;
        } else {
            return mid;
        }
    }
    // Find right part
    l = peak_pos;
    r = n - 1;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (mountainArr.get(mid) > target) {
            l = mid + 1;
        } else if (mountainArr.get(mid) < target) {
            r = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
        
    }
};