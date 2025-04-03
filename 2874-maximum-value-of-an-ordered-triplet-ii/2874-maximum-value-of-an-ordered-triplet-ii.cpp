class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long res = 0, d_max = 0, i_max = 0; 
        for(int k=0; k<n; k++){
            res = max(res, d_max * nums[k]);
            d_max = max(d_max, i_max - nums[k]);
            i_max = max(i_max, static_cast<long long>(nums[k]));
        }
        return res;
    }
};