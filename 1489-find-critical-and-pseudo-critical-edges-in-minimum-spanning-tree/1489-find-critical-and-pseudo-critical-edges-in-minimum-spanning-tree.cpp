class Solution {
public:
    class DisjointSet {
        vector<int> rank, parent, size;
    public:
        DisjointSet(int n) {
            rank.resize(n + 1, 0);
            parent.resize(n + 1);
            size.resize(n + 1);
            for (int i = 0; i <= n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findUPar(int node) {
            if (node == parent[node])
                return node;
            return parent[node] = findUPar(parent[node]);
        }

        void unionByRank(int u, int v) {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if (ulp_u == ulp_v) return;
            if (rank[ulp_u] < rank[ulp_v]) {
                parent[ulp_u] = ulp_v;
            }
            else if (rank[ulp_v] < rank[ulp_u]) {
                parent[ulp_v] = ulp_u;
            }
            else {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }

        void unionBySize(int u, int v) {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if (ulp_u == ulp_v) return;
            if (size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
    };
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges){
        
        DisjointSet ds(n);
        
        vector<vector<int>>newEdges = edges;
        int m = newEdges.size();
        for(int i=0;i<m;i++){
            newEdges[i].push_back(i);
        }
        
        sort(newEdges.begin(),newEdges.end(),[](auto &a,auto &b){
            return a[2]<b[2];
        });
        
        int mst=0;
        
        for(auto it: newEdges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            if(ds.findUPar(u)!=ds.findUPar(v)){
                ds.unionBySize(u,v);
                mst+=wt;
            }
        }
        
        vector<int>critical_edges;
        vector<int>pseudo_edges;
        
        for(int i=0;i<m;i++){
            
            DisjointSet ds1(m);
            int currMst = 0;
            for(int j=0;j<m;j++){
                
                if(i!=j){
                    
                    int u = newEdges[j][0];
                    int v = newEdges[j][1];
                    int wt= newEdges[j][2];
                    
                    if(ds1.findUPar(u)!=ds1.findUPar(v)){
                        ds1.unionBySize(u,v);
                        currMst+=wt;
                    }
                }
            }
            
            if(currMst>mst || currMst<mst){
                critical_edges.push_back(newEdges[i][3]);
            }else{
                DisjointSet ds3(m);
                
                ds3.unionBySize(newEdges[i][0],newEdges[i][1]);
                
                int forcedMst = newEdges[i][2];
                
                for(int j=0;j<m;j++){
                    
                    int u = newEdges[j][0];
                    int v = newEdges[j][1];
                    int wt = newEdges[j][2];
                    
                    if(ds3.findUPar(u)!=ds3.findUPar(v)){
                        ds3.unionBySize(u,v);
                        forcedMst+=wt;
                    }
                }
                if(forcedMst == mst){
                    pseudo_edges.push_back(newEdges[i][3]);
                }
            }
        }
        
        
        return {critical_edges,pseudo_edges};
    }
};