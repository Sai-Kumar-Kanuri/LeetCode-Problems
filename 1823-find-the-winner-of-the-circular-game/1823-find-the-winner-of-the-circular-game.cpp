class Solution {
public:
    void f(int i,vector<int>&arr,int k){
        
        if(arr.size()==1){
            return;
        }
        
        i = (i+k-1)%(arr.size());
        arr.erase(arr.begin()+i);
        
        f(i,arr,k);        
    }
    int findTheWinner(int n, int k) {
        vector<int>arr;
        
        for(int i=1;i<=n;i++){
            arr.push_back(i);
        }
        
        f(0,arr,k);
        
        return arr[0];
        
    }
};