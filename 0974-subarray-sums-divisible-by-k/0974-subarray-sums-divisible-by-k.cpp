class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0, sum = 0;
        unordered_map<int,int> mpp;
        mpp[0] = 1;

        for(int i=0;i<n;i++){
            sum += nums[i];
            int rem = sum % k;

            if(rem < 0){
                rem += k;
            }

            if(mpp.find(rem) != mpp.end()){
                cnt += mpp[rem];
            }
            mpp[rem]++;
        }
        return cnt;
    }
};