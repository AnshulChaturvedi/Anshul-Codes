class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        int flipped = 0;
        vector<int> isFlipped(n, 0);

        for (int i = 0; i < n; ++i) {
            if (i >= k) {
                flipped ^= isFlipped[i - k];
            }

            if (nums[i] == flipped) {
                if (i + k > n) {
                    return -1;
                }
                cnt++;
                flipped ^= 1;
                isFlipped[i] = 1;
            }
        }
        return cnt;
    }
};
