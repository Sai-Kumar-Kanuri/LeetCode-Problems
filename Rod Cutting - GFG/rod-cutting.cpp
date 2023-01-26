//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  int f(int ind,int n,int cuts[],vector<vector<int>>&dp){
        if(ind==0){
            return n*cuts[0];
        }
        if(dp[ind][n]!=-1){
			return dp[ind][n];
		}
        int nottake=0+f(ind-1,n,cuts,dp);
        
        int take=INT_MIN;
        int rodlength = ind+1;
        if(rodlength<=n) {
            take = cuts[ind]+f(ind,n-rodlength,cuts,dp);
        }
        
        return dp[ind][n]=max(take,nottake);
        
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(n-1,n,price,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends