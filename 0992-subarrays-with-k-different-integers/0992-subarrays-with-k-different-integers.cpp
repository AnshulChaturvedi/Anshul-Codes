class Solution {
private:
    int findCount(vector<int>& nums,int n,int k){
        int ans = 0;
        int i=0, j=0;
        unordered_map<int,int> mpp;
        while(j<n){
            mpp[nums[j]]++;

            while(mpp.size() > k){
                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0){
                    mpp.erase(nums[i]);
                }
                i++;
            }
            if(mpp.size() <= k){
                ans += j-i+1;
            }
            j++;

        }
        return ans;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        
        int cntForK = findCount(nums,n,k);
        int cntForKminusOne = findCount(nums,n,k-1);

        return (cntForK - cntForKminusOne);
    }
};