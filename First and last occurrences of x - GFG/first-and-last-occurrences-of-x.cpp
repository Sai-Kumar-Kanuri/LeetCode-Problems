//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


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


vector<int> find(int arr[], int n , int x )
{
    // code here
    
     vector<int>ans= {-1,-1};
     
     
     int first=f(arr,n,x,true);
     int last=f(arr,n,x,false);
     
     
     ans[0]=first;
     ans[1]=last;
     
     return ans;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends