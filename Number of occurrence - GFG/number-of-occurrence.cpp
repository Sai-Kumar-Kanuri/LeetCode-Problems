//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
		
	int f(int arr[], int n , int x ,bool findFirst)
    {
        int start=0;
        int end=n-1;
        int ans=-1;
        while(start<=end)
        {
            int mid = (start+end)/2;
            
            if(arr[mid]<x)
            {
                start=mid+1;
            }
            
            else if(arr[mid]>x)
            {
                end=mid-1;
            }
            
            
            else{
                ans=mid;
                
                if(findFirst)
                {
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
        }
        
        return ans;
    }
	int count(int arr[], int n, int x) {
	    int first=f(arr,n,x,true);
	    int last=f(arr,n,x,false);
	    
	   // cout<<first<<" "<<last<<endl;
	    
	    if(first>=0 && last>=0 && first!=last)
	    {
	        return last-first+1;
	    }
	    
	    else if(last==first && first>=0 && last>=0)
	    {
	        return 1;
	    }
	    
	   // else if(first==0)
	   // {
	   //     return last;
	   // }
	    
	    return 0;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends