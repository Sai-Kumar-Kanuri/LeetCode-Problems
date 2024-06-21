class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        int ans = 0;

        for(int i=0;i<grumpy.size();i++){
            if(grumpy[i]==0){
                ans+=customers[i];
            }
        }


        int i=0;
        int maxi = 0;
        while(i<grumpy.size()-minutes+1){
            // int j = i;
            int cnt = 0;
            for(int j = i;j<i+minutes;j++){
                if(grumpy[j]==1){
                    cnt+=customers[j];
                }
            }

            cout<<i<<" "<<cnt<<endl;

            maxi=max(maxi,cnt);
            i++;
        }

        // cout<<maxi<<endl;

        return maxi+ans;
    }
};