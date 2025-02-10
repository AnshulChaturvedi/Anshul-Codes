class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        // int ans = nums[0], sum = 0;
        // for (int i = 0; i < n; ++i) {
        //     sum += nums[i];
        //     ans = max(ans, sum);
        //     sum = max(sum, 0);
        // }
        // return ans;
        int max_normal = INT_MIN, sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            max_normal = max(max_normal, sum);
            sum = max(sum, 0);
        }
        int totalSum = accumulate(nums.begin(), nums.end(),0);
        int min_normal = INT_MAX;
        sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            min_normal = min(min_normal, sum);
            sum = min(sum, 0);
        }
        int max_circular = totalSum - min_normal;
        if(max_circular == 0) return max_normal;
        return max(max_normal, max_circular);
    }
};