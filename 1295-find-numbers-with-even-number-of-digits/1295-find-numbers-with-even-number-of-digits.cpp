class Solution {
public:
    
    int numberOfDigits(int x)
    {
        int count=0;
        while(x>0)
        {
            count++;
            x=x/10;
        }
        return count;
    }
    
    int findNumbers(vector<int>& nums) {
        int even_count=0;
        for(auto num: nums)
        {
            int n=numberOfDigits(num);
            if(n%2==0)
            {
                even_count+=1;
            }
        }
        
        return even_count;
    }
};