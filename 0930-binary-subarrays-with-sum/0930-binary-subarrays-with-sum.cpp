class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        int n = nums.size();
        int prefixSum = 0;
        int cnt = 0;

        unordered_map<int,int> prefixSumCount;
        prefixSumCount[0] = 1;

        for(int i=0;i<n;i++){
            prefixSum += nums[i];

            if(prefixSumCount.find(prefixSum - k) != prefixSumCount.end()){
                cnt += prefixSumCount[prefixSum - k];
            }

            prefixSumCount[prefixSum]++;
        }

        return cnt;
    }
};