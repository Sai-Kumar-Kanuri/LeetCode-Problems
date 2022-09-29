class Solution {
public:
    
    int findCrossOver(vector<int>& arr,int low,int high,int x)
    {
        // if(high==(low+1))
        // {
        //     return low;
        // }
        
        if(arr[high]<=x)
        {
            return high;
        }
        
        if(arr[low]>x)
        {
            return low;
        }
        
        int mid=low+(high-low)/2;
        
        if(arr[mid]==x)
        {
            return mid;
        }
        
        if(arr[mid]<x && arr[mid+1]>x)
        {
            return mid;
        }
        
        if(arr[mid]<x)
        {
           return findCrossOver(arr,mid+1,high,x); 
        }
        return findCrossOver(arr,low,mid-1,x);
        
    }
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int l=findCrossOver(arr,0,n-1,x);
        int r=l+1;
        int count=0;
        
        cout<<l<<"  "<<r<<endl;
         
        vector<int>result;
     
        
        while(l>=0 && r<n && count<k)
        {
            if((x-arr[l])<=(arr[r]-x))
            {
                cout<<arr[l]<<" "<<arr[r]<<endl;
                result.push_back(arr[l]);
                l--;
                cout<<l<<endl;
            }
            else
            {
                cout<<arr[r]<<endl;
                result.push_back(arr[r]);
                r++;   
            }
            
            count++;
        }
        
        while(l>=0 && count<k)
        {
            result.push_back(arr[l--]);
            count++;
        }
        
          while(r<n && count<k)
        {
            result.push_back(arr[r++]);
            count++;
        }
        
        sort(result.begin(),result.end());
        return result;
        
        
    }
};