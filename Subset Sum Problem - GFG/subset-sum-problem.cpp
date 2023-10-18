//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
    public:
        bool solve(vector<int> & arr, int ind, int sum, vector<vector<int>> &dp){
            if(sum == 0) return true;
            if(ind == 0) return (arr[0] == sum);
            if(dp[ind][sum] != -1) return dp[ind][sum];
            bool notTake = solve(arr, ind-1, sum, dp);
            bool take = false;
            if(arr[ind] <= sum) take = solve(arr, ind-1, sum-arr[ind], dp);
            return dp[ind][sum] = (notTake || take);
        }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return solve(arr, n-1, sum, dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends