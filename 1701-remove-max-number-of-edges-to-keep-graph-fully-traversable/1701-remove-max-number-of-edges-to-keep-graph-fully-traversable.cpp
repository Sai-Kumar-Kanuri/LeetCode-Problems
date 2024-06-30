class DisjointSet
{
    vector<int> rank, parent,size;
    int components;

public:
    DisjointSet(int n){
        rank.resize(n + 1);
        parent.resize(n + 1);
        size.resize(n+1);
        components=n; // to keep track of edges
        for (int i = 0; i <= n; i++){
            parent[i] = i;
            size[i]=1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node]){
            return node;
        }

        return parent[node]=findUPar(parent[node]);
    }

    bool unionByRank(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u==ulp_v){
         return false;   
        }

        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }else{
            parent[ulp_v]=ulp_u;
            rank[ulp_v]++;
        }

        components--;

        return true;

    }


    bool unionBySize(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u==ulp_v){
            return false;
        }

        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }else {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }

        components--;

        return true;
    }

    bool isConnected(){
        return components == 1;
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        DisjointSet Alice(n),Bob(n);
        int edgesRequired=0;


        for(auto it : edges){
            if(it[0]==3){
               edgesRequired+=(Alice.unionBySize(it[1],it[2]) | Bob.unionBySize(it[1],it[2]));
            }
        }

        for(auto it : edges){
            if(it[0]==2){
                edgesRequired+=Bob.unionBySize(it[1],it[2]);
            }else if(it[0]==1){
                edgesRequired+=Alice.unionBySize(it[1],it[2]);
            }
        }

        if(Alice.isConnected() && Bob.isConnected()){
            return edges.size() - edgesRequired;
        }

        return -1;
    }
};