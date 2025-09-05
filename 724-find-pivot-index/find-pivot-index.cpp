class Solution {
public:
    int pivotIndex(vector<int>& nums) {
    int t_sum=accumulate(nums.begin(),nums.end(),0);
    int leftsum=0;
    int target_index=-1;
    for(int i=0;i<nums.size();i++){
        if(i==0){
            leftsum=0;
        }else{
            leftsum+=nums[i-1];
        }
        if(leftsum==t_sum-leftsum-nums[i]){
            target_index=i;
            break;
        }
    }
     return target_index;   
    }
};