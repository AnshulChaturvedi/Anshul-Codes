class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        // int cnt = 0;
        // for(int i=0; i<nums.size(); i++){
        //     for(int j=i+1; j<nums.size(); j++){
        //         if(nums[j]-nums[i] != j - i) cnt++;
        //     }
        // }
        // return cnt;

        long long cntGood = 0;
        unordered_map<int,int> mpp;
        long long n = nums.size();
        for(long long i=0; i<n; i++){
            int val = i-nums[i];
            if(mpp.find(val) != mpp.end()) cntGood += mpp[val];
            mpp[val]++;
        }
        long long ans = (n*(n-1))/2 - cntGood;
        return ans;
    }
};