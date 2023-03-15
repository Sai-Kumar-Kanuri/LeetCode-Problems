//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long, long>> adj[n];
        for(auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<long long> count_time(n, LLONG_MAX), ways(n, 0); //LLONG_MAX: maximum value that can be stored in a long long
        count_time[0] = 0;
        ways[0] = 1;
        typedef pair<long, long> pi;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({0, 0});
        long long mod = (int)(1e9 + 7); // 1e9 = 10^9
        
        while(pq.size()) {
            long long time = pq.top().first;
            long long node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]) {
                long long child = it.first;
                long long time_wt = it.second;
                if(time + time_wt < count_time[child]) {
                    count_time[child] = time + time_wt;
                    ways[child] = ways[node];
                    pq.push({count_time[child], child});
                }
                else if(time + time_wt == count_time[child]) {
                    ways[child] = (ways[child] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends