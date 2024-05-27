class Solution {
private:
    void solve(int index, vector<int> result,vector<vector<int>> &ans,vector<int> &nums){
        if(index >= nums.size()){
            ans.push_back(result);
            return;
        }
        result.push_back(nums[index]);
        solve(index+1,result,ans,nums);
        result.pop_back();
        solve(index+1,result,ans,nums);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> result;
        solve(0,result,ans,nums);
        return ans;
    }
};