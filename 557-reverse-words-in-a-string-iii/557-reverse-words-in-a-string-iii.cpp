class Solution {
public:
    string reverseWords(string s) {
        int start_index=0,end_index=0;
        for(end_index=0;end_index<s.length();end_index++)
        {
            if(s[end_index]==' ')
            {
                reverse(s.begin()+start_index,s.begin()+end_index);
                start_index=end_index+1;
            }
            if(end_index==s.length()-1)
            {
                                reverse(s.begin()+start_index,s.begin()+end_index+1);
            }
        }
        return s;
    }
};