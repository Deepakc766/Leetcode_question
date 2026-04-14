class Solution {
public:
int recsol(int n){
    if(n==0 | n==1)return n;
    int ans=fib(n-1)+fib(n-2);
    return ans;
}

int memsol(int n,vector<int>&dp){
    if(n==0 | n==1)return n;
    if(dp[n]!=-1)return dp[n];
    dp[n]=fib(n-1)+fib(n-2);
    return dp[n];
}
    int fib(int n) {
        vector<int>dp(n+1,-1);
        return memsol(n,dp);   
    }
};