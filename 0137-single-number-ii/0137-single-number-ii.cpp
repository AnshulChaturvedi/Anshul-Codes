class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = 1;
        while(i<nums.size()){
            if(nums[i] != nums[i-1]){
                return nums[i-1];
            }
            i += 3;
        }
        return nums[nums.size()-1];
    }
};