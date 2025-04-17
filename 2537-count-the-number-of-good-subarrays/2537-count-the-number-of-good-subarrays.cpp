class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int same = 0, right = -1;
        long long ans = 0;
        int n = nums.size();
        unordered_map<int,int> cnt;
        for(int left=0; left<n; left++){
            while(same < k && right+1 < n){
                right++;
                same += cnt[nums[right]];
                cnt[nums[right]]++;
            }
            if(same >= k){
                ans += n-right;
            }
            cnt[nums[left]]--;
            same -= cnt[nums[left]];
        }
        return ans;
    }
};