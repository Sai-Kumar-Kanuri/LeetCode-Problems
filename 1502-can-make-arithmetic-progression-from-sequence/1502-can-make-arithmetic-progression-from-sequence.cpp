class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int common=arr[1]-arr[0];
        for(int i=1;i<n;i++)
        {
            if(arr[i]-arr[i-1]!=common)
            {
                return false;
            }
        }
        
        return true;
    }
};