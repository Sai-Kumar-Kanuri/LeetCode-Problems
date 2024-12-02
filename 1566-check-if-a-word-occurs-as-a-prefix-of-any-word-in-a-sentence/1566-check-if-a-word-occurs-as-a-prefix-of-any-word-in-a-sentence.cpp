class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {

        // vector<pair<string,int>>arr;

        int i = 1;
        string word = "";
        for(auto it : sentence){
            if(it==' '){
                // arr.push_back({word,i});
                if(word.find(searchWord)==0){
                    return i;
                }
                i++;
                word="";
            }else{
                word+=it;
            }
        }   

        if(word.find(searchWord)==0){
            return i;
        }

        // arr.push_back({word,i});

        // for(auto it : arr){

        //     string s = it.first;
        //     int n = it.second;

        //     if(s.find(searchWord)==0){
        //         return n;
        //     }
        // }

        return -1;
    }
};