class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>answer;
        int n=numbers.size();
        cout<<n;
        // for(int i=0;i<numbers.size();i++)
        // {
        //     int find=target-numbers[i];
        //     for(int j=i+1;j<numbers.size();j++)
        //     {
        //         if(find==numbers[j])
        //         {
        //             answer.push_back(i+1);
        //             answer.push_back(j+1);
        //         }
        //         else if(numbers[j]>find)
        //         {
        //             break;
        //         }
        //     }
        // }
        
        int low=0,high=n-1;
        while(low<high)
        {
            int sum = numbers[low]+numbers[high];
            if(sum==target)
            {
                answer.push_back(low+1);
                answer.push_back(high+1);
                break;
            }
            else if(sum>target)
            {
                high--;
            }
            else
            {
                low++;
            }
        }
        return answer;
    }
};