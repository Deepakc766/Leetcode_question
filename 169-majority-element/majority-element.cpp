class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        int count = 0;
        int x = 0;

        for(int i =0;i<n;i++){

            if(count ==0){
                x = nums[i];
            }

            if(nums[i]!=x){
                count--;
            }

            else{
                count++;
            }
        }

        return x;
        
    }
};