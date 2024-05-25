class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0,index = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                cnt++;
            }
            else{
                nums[index] = nums[i];
                index++;
            }
        }
        for(int i=n-1;i>=n-cnt;i--){
            nums[i] = 0;
        }
    }
};