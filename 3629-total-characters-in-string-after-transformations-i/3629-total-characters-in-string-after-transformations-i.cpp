class Solution {
public:
    const int MOD = 1e9+7;
    int lengthAfterTransformations(string s, int t) {
        // unordered_map<char,long long>mp;

        vector<int>freq(26,0);
        for(auto it : s){
            // mp[it]++;
            freq[it-'a']++;
        }

        while(t--){
            vector<int>nfreq(26,0);

            for(int i=0;i<25;i++){
                nfreq[i+1] = freq[i];
            }

            nfreq[0]=freq[25];
            nfreq[1]=(nfreq[1]+freq[25])%MOD;


            freq = nfreq;
             

            
        }

        long long result = 0;
        for (auto count : freq) {
            result = (result + count) % MOD;
        }

        return result;
    }
};