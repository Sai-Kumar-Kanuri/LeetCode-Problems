//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    void printStrictlyInc(string result, int n, char prev,vector<string>&ans)
{
	if (n)
	{
		// start from the next digit (the last digit is `prev`)
		for (char ch = prev +1; ch <= '9'; ch++) {
			printStrictlyInc(result + ch, n - 1, ch,ans);
		}
	}
	// if the string becomes n–digit, print it
	else {
		ans.push_back(result);
		// cout << result << " ";
	}
}
    vector<int> increasingNumbers(int N)
    {
        // Write Your Code here
        // string result;
        // vector<string>ans;
        // vector<int>fanser;
        // findStrictlyIncreasing(ans,'0',N,result);
        // for(auto x:ans){
        //     fanser.push_back(stoi(x));
        // }
        // return fanser
        string result;
	    vector<string>res;
	    vector<int>ans;
	    if( N==1){
	        ans.push_back(0);
	    }
	    printStrictlyInc(result, N, '0',res);
	    for(auto x:res){
	        ans.push_back(stoi(x));
	    }
	    return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> ans = ob.increasingNumbers(N);
        for(auto num : ans){
            cout<< num <<" ";
        }
        cout<<endl;
        
    }
    return 0;
}
// } Driver Code Ends