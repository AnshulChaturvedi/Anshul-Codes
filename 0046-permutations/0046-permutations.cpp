class Solution {
private:
    void solve(vector<int> result,vector<vector<int>> &ans,vector<int> &freq,vector<int> &nums){
        if(result.size() == nums.size()){
            ans.push_back(result);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                result.push_back(nums[i]);
                freq[i] = 1;
                solve(result,ans,freq,nums);
                freq[i] = 0;
                result.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> result;
        vector<int> freq(n,0);
        solve(result,ans,freq,nums);
        return ans;
    }
};