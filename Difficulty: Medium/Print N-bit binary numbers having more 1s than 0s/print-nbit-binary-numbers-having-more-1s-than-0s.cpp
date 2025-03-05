//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++
class Solution{
public:	
void generateStrings(string&tmp,int zeroes,int ones,vector<string>&ans,int n){
    if(tmp.size()==n){
        
            ans.push_back(tmp);
    
        return;
    }
    tmp.push_back('1');
    generateStrings(tmp,zeroes,ones+1,ans,n);
    tmp.pop_back();
    if(ones>zeroes){
    tmp.push_back('0');
    generateStrings(tmp,zeroes+1,ones,ans,n);
    tmp.pop_back();
        
    }
    
}
	vector<string> NBitBinary(int n)
	{
	  vector<string>ans;
	  string tmp="";
	  int zeroCnt=0,oneCnt=0;
	  generateStrings(tmp,zeroCnt,oneCnt,ans,n);
	  return ans;
	}
};


//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	
cout << "~" << "\n";
}

    return 0;
}
// } Driver Code Ends