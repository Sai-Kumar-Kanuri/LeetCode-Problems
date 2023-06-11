//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

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
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
            long long start=0;
        
        long long end=n-1;
        
        sort(arr,arr+n);
        
        while(start<=end)
        {
            long long mid= (start+end)/2;
            
            if(arr[mid]<x)
            {
                start=mid+1;
            }
            
            else if(arr[mid]>x)
            {
                end=mid-1;
            }
            else{
                return {arr[mid],arr[mid]};
            }
        }
        
        
        if(end<0)
        {
            return {-1,arr[start]};
        }
        
        else if(start>n-1)
        {
            return {arr[end],-1};
        }
        return {arr[end],arr[start]};
}