class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        int window = n-k;
        int total_pts = 0;
        for(auto &num : nums){
            total_pts += num;
        }

        int ans = 0, sum = 0;
        for(int i=0;i<window;i++){
            sum += nums[i];
        }
        ans = max(ans, total_pts-sum);
        for(int i=window;i<n;i++){
            sum = sum - nums[i-window] + nums[i];
            ans = max(ans,total_pts-sum);
        }
        return ans;
    }
};