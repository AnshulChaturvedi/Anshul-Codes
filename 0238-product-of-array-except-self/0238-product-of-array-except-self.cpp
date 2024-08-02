class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> prefixMul(n), suffixMul(n);
        int val = 1;
        for(int i=0;i<n;i++){
            val *= nums[i];
            prefixMul[i] = val;
        }
        val = 1;
        for(int i=n-1;i>=0;i--){
            val *= nums[i];
            suffixMul[i] = val;
        }
        for(int i=1;i<n-1;i++){
            ans[i] = prefixMul[i-1]*suffixMul[i+1];
        }
        ans[0] = suffixMul[1];
        ans[n-1] = prefixMul[n-2];
        return ans;
    }
};