//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int searchInsertK(vector<int>arr, int N, int k)
    {
        // code here
        
        int start=0;
        int end=N-1;
        
        while(start<=end)
        {
            int mid=(start+end)/2;
            
            
            if(arr[mid]<k)
            {
                start=mid+1;
            }
            
            else if(arr[mid]>k)
            {
                end=mid-1;
            }
            
            else{
                return mid;
            }
        }
        
        return start;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<int>Arr(N);
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.searchInsertK(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends