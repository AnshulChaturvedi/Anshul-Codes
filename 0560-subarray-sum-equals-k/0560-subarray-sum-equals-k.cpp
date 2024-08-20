class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> prefixSumCnt;
        prefixSumCnt[0] = 1;
        int prefixSum = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            prefixSum += nums[i];
            if(prefixSumCnt.find(prefixSum - k) != prefixSumCnt.end()){
                ans += prefixSumCnt[prefixSum-k];
            }
            prefixSumCnt[prefixSum]++;
        }
        return ans;
    }
};