class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        for(int k=2; k<n; k++){
            int max_i = nums[0];
            for(int j=1; j<k; j++){
                res = max(res, (long long)(max_i - nums[j])*nums[k]);
                max_i = max(max_i, nums[j]);
            }
        }
        return res;
    }
};