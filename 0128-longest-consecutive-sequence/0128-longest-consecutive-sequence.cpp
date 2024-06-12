class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        priority_queue <int, vector<int>, greater<int>> pq;

        for(auto it : nums){
            pq.push(it);
        }

        int len = 1;
        int maxi = 1;
        int prev = pq.top();
        pq.pop();

        while(!pq.empty()){

            int x = pq.top();

            pq.pop();

            if(prev+1==x){   
                len++;
            }else if (x != prev) {
                maxi = max(maxi,len);
                len=1;
            }

            prev=x;
            
        }

        maxi = max(maxi,len);

        return maxi;

    }
};