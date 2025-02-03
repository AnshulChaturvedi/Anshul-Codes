class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ansForLie = 1, cnt1 = 1;
        int ansForLde = 1, cnt2 = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] > nums[i-1]){
                cnt1++;
                cnt2 = 1;
            }
            else if(nums[i] < nums[i-1]){
                cnt2++;
                cnt1 = 1;
            }
            else{
                cnt1 = cnt2 = 1;
            }
            ansForLie = max(ansForLie, cnt1);
            ansForLde = max(ansForLde, cnt2);
        }
        return max(ansForLie, ansForLde);
    }
};