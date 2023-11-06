class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<int>arr;
        int pos=1;
        vector<string>ans;

        for(int i=0;i<target.size();i++){
            while(pos<target[i]){
                ans.push_back("Push");
                ans.push_back("Pop");
                pos++;
            }

            ans.push_back("Push");
            pos++;
        }

        return ans;
        
    }
};