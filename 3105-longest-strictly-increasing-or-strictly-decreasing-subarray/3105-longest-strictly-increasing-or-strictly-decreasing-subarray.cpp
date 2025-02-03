class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ansForLie = 1, cnt1 = 1, lie = nums[0];
        int ansForLde = 1, cnt2 = 1, lde = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i] > lie){
                cnt1++;
                ansForLie = max(ansForLie, cnt1);
            }
            else{
                cnt1 = 1;
            }
            if(nums[i] < lde){
                cnt2++;
                ansForLde = max(ansForLde, cnt2);
            }
            else{
                cnt2 = 1;
            }
            lie = lde = nums[i];
        }
        return max(ansForLie, ansForLde);
    }
};