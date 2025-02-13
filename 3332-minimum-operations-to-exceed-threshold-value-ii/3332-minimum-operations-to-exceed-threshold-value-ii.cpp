class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue <long long int, vector<long long int>, greater<long long int>> pq;

        for(auto it:nums){
            pq.push(it);
        }

        int ans=0;

        while(pq.top()<k){

            long long int num1 = pq.top();
            pq.pop();
            long long int num2 = pq.top();
            pq.pop();

            long long int num3 = (min(num1,num2)*2) + max(num1,num2);
            pq.push(num3);

            ans++;
        }

        return ans;
    }
};