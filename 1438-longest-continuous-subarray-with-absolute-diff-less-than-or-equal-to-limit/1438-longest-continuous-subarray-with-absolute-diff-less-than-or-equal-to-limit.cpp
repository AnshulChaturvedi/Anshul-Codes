class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxDeque, minDeque;
        int i = 0, j;
        int maxLen = 0;
        
        for (j = 0; j < nums.size(); ++j) {
            while (!maxDeque.empty() && nums[j] > maxDeque.back()) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(nums[j]);
            
            while (!minDeque.empty() && nums[j] < minDeque.back()) {
                minDeque.pop_back();
            }
            minDeque.push_back(nums[j]);
            
            while (maxDeque.front() - minDeque.front() > limit) {
                if (nums[i] == maxDeque.front()) {
                    maxDeque.pop_front();
                }
                if (nums[i] == minDeque.front()) {
                    minDeque.pop_front();
                }
                ++i;
            }
            
            maxLen = max(maxLen, j - i + 1);
        }
        
        return maxLen;
    }
};