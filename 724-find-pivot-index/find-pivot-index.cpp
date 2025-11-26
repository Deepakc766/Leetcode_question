class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int leftsum=0;
        int l_index=-1;
        // if(nums.size()==0 || nums.size()==1)return -1;
        for(int i=0;i<nums.size();i++){
            if(leftsum==sum-leftsum-nums[i]){
                l_index=i;
                break;
            }
            leftsum+=nums[i];
        }

  return l_index;
    }
};