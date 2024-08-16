class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        

        int maxi = arrays[0].back();
        int mini = arrays[0].front();

        int diff = INT_MIN;

        for(int i=1;i<arrays.size();i++){
            diff = max({diff,abs(maxi-arrays[i].front()),abs(arrays[i].back()-mini)});
            cout<<diff<<" "<<maxi<<" "<<mini<<" "<<endl;
            mini=min(mini,arrays[i].front());
            maxi=max(maxi,arrays[i].back());
        }

        return diff;
    }
};