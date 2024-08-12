class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {

        int ans=0;

        for(auto cmd : commands){

           if(cmd=="UP"){
            ans-=n;
           }

           if(cmd=="RIGHT"){
            ans+=1;
           }

           if(cmd=="DOWN"){
            ans+=n;
           }

           if(cmd=="LEFT"){
            ans-=1;
           }


        }

        return ans;
    }
};