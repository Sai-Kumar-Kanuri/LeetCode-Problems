class Solution {
public:
//    void getPartition(string s,int idx,vector<string>&path,vector<vector<string>>&ans){
//         if(s.size()==idx){
//             ans.push_back(path);
//             return;
//         }
        
//         for(int i=idx;i<s.size();++i){
//             if(isPalindrome(s,idx,i)){
//                 path.push_back(s.substr(idx,i-idx+1));
//                 getPartition(s,idx+1,path,ans);
//                 path.pop_back();
//             }
//         }
//     }

//  bool isPalindrome(string s,int start,int end){
//         while(start<=end){
//             if(s[start++]!=s[end--]){
//                 return false;
//             }
//         }
//         return true;
//     }
//     vector<vector<string>> partition(string s) {
//         vector<string>path;
//         vector<vector<string>>ans;
//         getPartition(s,0,path,ans);
//         return ans;
        
//     }
    vector < vector < string >> partition(string s) {
      vector < vector < string > > res;
      vector < string > path;
      partitionHelper(0, s, path, res);
      return res;
    }

  void partitionHelper(int index, string s, vector < string > & path,
    vector < vector < string > > & res) {
    if (index == s.size()) {
      res.push_back(path);
      return;
    }
    for (int i = index; i < s.size(); ++i) {
      if (isPalindrome(s, index, i)) {
        path.push_back(s.substr(index, i - index + 1));
        partitionHelper(i + 1, s, path, res);
        path.pop_back();
      }
    }
  }

  bool isPalindrome(string s, int start, int end) {
    while (start <= end) {
      if (s[start++] != s[end--])
        return false;
    }
    return true;
  }
   
};