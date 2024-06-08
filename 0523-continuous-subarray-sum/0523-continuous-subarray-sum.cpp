class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> remainderMap;
        remainderMap[0] = -1;
        int cumSum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            cumSum += nums[i];
            int remainder = cumSum % k;

            if (remainderMap.find(remainder) != remainderMap.end()) {
                if (i - remainderMap[remainder] > 1) {
                    return true;
                }
            } else {
                remainderMap[remainder] = i;
            }
        }
        return false;
    }
};
