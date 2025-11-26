class Solution {
public:
void solve(vector<int>& nums,int &minprice,int i,int &maxprofit){
    if(i>=nums.size())return;
    minprice=min(minprice,nums[i]);
    maxprofit=max(maxprofit,nums[i]-minprice);
    solve(nums,minprice,i+1,maxprofit);


}

int memo(vector<int>& nums,int &minprice,int i,int &maxprofit,vector<int> &dp){
    if(i>=nums.size())return 0;
    minprice=min(minprice,nums[i]);
    maxprofit=max(maxprofit,nums[i]-minprice);
    if(dp[i]!=INT_MIN)return dp[i];
    int next=memo(nums,minprice,i+1,maxprofit,dp);
    dp[i]=max(maxprofit,next);
return dp[i];
}
    int maxProfit(vector<int>& prices) {
        int minprice=INT_MAX;
        int maxprice=INT_MIN;
        int maxprofit=0;
        vector<int>dp(prices.size()+1,INT_MIN);
     return  memo(prices,minprice,0,maxprofit,dp);
        
    }
};