class Solution {
private:
    void rec(int i,vector<int> result,vector<vector<int>> &ans,vector<int>& nums){
        if(i == nums.size()){
            ans.push_back(result);
            return;
        }
        result.push_back(nums[i]);
        rec(i+1,result,ans,nums);
        result.pop_back();
        rec(i+1,result,ans,nums);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> result;
        rec(0,result,ans,nums);
        return ans;
    }
};