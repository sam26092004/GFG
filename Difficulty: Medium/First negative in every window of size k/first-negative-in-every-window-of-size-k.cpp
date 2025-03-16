//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
    deque<int>dq;
    vector<int>ans;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<0) dq.push_back(i);
        while( !dq.empty() && i-dq.front()>= k){
            dq.pop_front();
          
        }
        if(i+1>=k){
            if(dq.empty()){
                 ans.push_back(0);
                 continue;
            }
            ans.push_back(arr[dq.front()]);
        }
    }
    return ans;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.FirstNegativeInteger(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends