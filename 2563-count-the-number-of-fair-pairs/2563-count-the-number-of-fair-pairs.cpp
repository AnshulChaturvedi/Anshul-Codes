class Solution {
public:

    // largest number less than (upper + 1 - nums[i]) OR (lower - nums[i]);

    int binSearch(int l, int r, int target, vector<int> &nums){
        // returns largest i, where nums[i] < target
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] >= target){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        long long cnt = 0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            int up = upper - nums[i];
            int low = lower - nums[i];
            cnt += 1LL * (binSearch(i+1, n-1, up + 1, nums) - binSearch(i+1, n-1, low, nums));
        }
        return cnt;
    }
};