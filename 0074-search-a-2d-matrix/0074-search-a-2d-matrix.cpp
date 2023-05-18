class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start=0;
        int last=matrix.size()-1;
        
        int rlast=matrix[0].size()-1;
        if(matrix[last][rlast]==target)
            return true;
        
        cout<<last<<" "<<rlast<<endl;
        
        while(start<last)
        {
            int mid=(start+last)/2;
            
            if(matrix[mid][rlast]>target)
            {
                last=mid;
            }
            
            else if(matrix[mid][rlast]<target)
            {
                start=mid+1;
            }
            
            else{
                return true;
            }
        }
        start=0;
        while(start<rlast)
        {
            int mid=(start+rlast)/2;
            
            if(matrix[last][mid]>target)
            {
                rlast=mid;
            }
            
            else if(matrix[last][mid]<target)
            {
                start=mid+1;
            }
            
            else{
                return true;
            }
        }
        return false;
    }
};