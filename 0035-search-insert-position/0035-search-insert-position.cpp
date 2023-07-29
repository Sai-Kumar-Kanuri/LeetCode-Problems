#include <algorithm>
class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        
        int i = lower_bound(arr.begin(),arr.end(),target)-arr.begin();
        return i;
        
        
    }
};