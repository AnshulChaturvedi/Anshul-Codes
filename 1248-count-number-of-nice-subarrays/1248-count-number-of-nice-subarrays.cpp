class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]&1){
                nums[i] = 1;
            }
            else{
                nums[i] = 0;
            }
        }

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