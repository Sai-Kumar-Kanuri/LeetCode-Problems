//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    class DisjointSet{
        
        public:
        vector<int>parent,size;
        DisjointSet(int n){
            parent.resize(n+1);
            size.resize(n+1);
            for(int i=0;i<=n;i++){
                parent[i]=i;
                size[i]=1;
            }
        }
        
        int findUPar(int node){
            if(parent[node]==node){
                return node;
            }
            
            return findUPar(parent[node]);
        }
        
        void unionBySize(int u,int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            
            if(ulp_u==ulp_v){
                return;
            }
            
            if(size[ulp_u]<size[ulp_v]){
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }else{
                parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
        }
    };
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        
        DisjointSet ds(n);
        int cntExtra=0;
        for(auto it:edge){
            int u = it[0];
            int v = it[1];
            
            if(ds.findUPar(u) == ds.findUPar(v)){
                cntExtra++;
            }
            
            ds.unionBySize(u,v);
        }
        
        int cnt=0;
        
        
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i){
                cnt++;
            }
        }
        
        int ans=cnt-1;
        if(ans<=cntExtra){
            return cnt-1;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends