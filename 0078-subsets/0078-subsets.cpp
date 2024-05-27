class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        int subsets = (1<<n);
        for(int i=0;i<subsets-1;i++){
            vector<int> result;
            for(int j=0;j<n;j++){
                if(i & (1<<j)){
                    result.push_back(nums[j]);
                }
            }
            ans.push_back(result);
        }
        ans.push_back(nums);
        return ans;
    }
};