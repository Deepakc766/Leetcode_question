class Solution {
public:
int LIS(vector<int>& nums,int i,int lastindex){
    if(i==nums.size())return 0;

    int curr=nums[i];
    int inc=0;
    if(lastindex==-1 || curr>nums[lastindex]){
        inc=1+LIS(nums,i+1,i);
    }
    int exc=0+LIS(nums,i+1,lastindex);
    return max(inc,exc);
}

int memo(vector<int>& nums,int i,int lastindex,vector<vector<int>>&dp){
    if(i==nums.size())return 0;
    if(dp[i][lastindex+1]!=-1)return dp[i][lastindex+1];
    int curr=nums[i];
    int inc=0;
    if(lastindex==-1 || curr>nums[lastindex]){
        inc=1+memo(nums,i+1,i,dp);
    }
    int exc=0+memo(nums,i+1,lastindex,dp);
    dp[i][lastindex+1]=max(inc,exc);
    return dp[i][lastindex+1];
}
    int lengthOfLIS(vector<int>& nums) {
      int i=0;
      int lastindex=-1;
      int last=INT_MIN;
      int n=nums.size();
      vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
      return memo(nums,i,lastindex,dp);
    }
};