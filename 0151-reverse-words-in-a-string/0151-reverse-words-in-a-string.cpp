class Solution {
public:
    string reverseWords(string s) {
        
        stack<string>arr;
        string str="";
        for(auto x:s)
        {
            if(x==' ')
            {
                if(str.length()>0)
                {
                    arr.push(str);
                    str.clear();
                }
            }
            else{
                str+=x;
            }
            // cout<<x<<endl;
        }
        if(str.length()>0) arr.push(str);
        string res;
        
        while(!arr.empty())
        {
            res+=arr.top();
            arr.pop();
            res+=' ';
        }
        res.pop_back();
        
        return res;
        
        // return res;
        
    }
};