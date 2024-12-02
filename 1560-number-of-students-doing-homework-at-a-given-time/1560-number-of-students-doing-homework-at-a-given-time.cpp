class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        
        int ans = 0;

        for(auto it : startTime){
            if(it<=queryTime){
                ans++;
            }
        }

        for(auto it : endTime){
            if(it<queryTime){
                ans--;
            }
        }

        return ans;
    }
};