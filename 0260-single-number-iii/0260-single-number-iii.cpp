class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        long num = 0;

        for(int i=0;i<n;i++){
            num ^= nums[i];
        }

        long firstBitSet = (num & (num-1))^num;

        int b1 = 0, b2 = 0;

        for(int i=0;i<n;i++){
            if(nums[i] & firstBitSet){
                b1 ^= nums[i];
            }
            else{
                b2 ^= nums[i];
            }
        }
        return {b1,b2};
    }
};