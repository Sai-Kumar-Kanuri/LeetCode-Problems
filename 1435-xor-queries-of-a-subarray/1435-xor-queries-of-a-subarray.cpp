class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {

        vector<int>ans;

        for(auto it : queries){

            int i=it[0];
            int j=it[1];

            int sum = arr[i];
            for(int k=i+1;k<=j;k++){
                sum^=arr[k];
            }

            ans.push_back(sum);
        }

        return ans;
    }
};