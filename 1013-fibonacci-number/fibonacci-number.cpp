class Solution {
public:
int recfib(int n){
    if(n==0 || n==1)return n;
    int ans=recfib(n-1)+recfib(n-2);
    return ans;
}

int memo(int n,vector<int>&dp){
    if(n==0 || n==1)return n;
    if(dp[n]!=-1)return dp[n];
    dp[n]=memo(n-1,dp)+memo(n-2,dp);
    return dp[n];
}
    int fib(int n) {
        // return recfib(n);
        vector<int>dp(n+1,-1);
        return memo(n,dp);
    }
};