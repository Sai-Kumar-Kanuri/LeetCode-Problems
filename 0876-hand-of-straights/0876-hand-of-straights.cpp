class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        if(hand.size()%groupSize!=0){
            return false;
        }

        map<int,int>mp;

        for(auto it:hand){
            mp[it]++;
        }

        while(!mp.empty()){
            int currCard = mp.begin()->first;

            for(int i=0;i<groupSize;i++){
                if(mp[currCard+i]==0){
                    return false;
                }

                mp[currCard+i]--;

                if(mp[currCard+i]<1){
                    mp.erase(currCard+i);
                }
            }
        }

        return true;
    }
    
};