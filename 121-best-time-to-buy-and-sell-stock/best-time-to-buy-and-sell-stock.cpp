class Solution {
public:
void solve(vector<int>& nums,int &minprice,int i,int &maxprofit){
    if(i>=nums.size())return;
    minprice=min(minprice,nums[i]);
    maxprofit=max(maxprofit,nums[i]-minprice);
    solve(nums,minprice,i+1,maxprofit);


}
    int maxProfit(vector<int>& prices) {
        int minprice=INT_MAX;
        int maxprice=INT_MIN;
        int maxprofit=0;
        solve(prices,minprice,0,maxprofit);
    return maxprofit;
        
    }
};