class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int>st;
        
        for(auto asteroid: asteroids){
            int flag=1;
            while(!st.empty() && (asteroid<0 && st.top()>0)){
                
                if(abs(asteroid)>abs(st.top())){
                    st.pop();
                    continue;
                }
                
                else if(abs(asteroid)==abs(st.top())){
                    st.pop();
                }
                
                flag=0;
                break;
            }
            if(flag==1){
                st.push(asteroid);
            }
        }
        
         vector<int> remainingAsteroids (st.size());
        for (int i = remainingAsteroids.size() - 1; i >= 0; i--){
            remainingAsteroids[i] = st.top();
            st.pop();
        }
        
        return remainingAsteroids;
    }
};