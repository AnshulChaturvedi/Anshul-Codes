class Solution {
private:
    void solve(int i,vector<vector<int>> &ans,vector<int> result,int target,vector<int> &candidates,int n){
        if(target == 0){
            ans.push_back(result);
            return;
        }
        if(i == n){
            return;
        }
        if(target > 0){
            result.push_back(candidates[i]);
            solve(i,ans,result,target-candidates[i],candidates,n);
            result.pop_back();
        }
        solve(i+1,ans,result,target,candidates,n);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> result;
        solve(0,ans,result,target,candidates,n);
        return ans;
    }
};