class Solution {
private:
    void rec(int i,vector<int> result,vector<vector<int>> &ans,
             vector<int> &candidates,int &target){
        if(target == 0){
            ans.push_back(result);
            return;
        }
        if(i == candidates.size()){
            return;
        }
        if(candidates[i] <= target){
            result.push_back(candidates[i]);
            target -= candidates[i];
            rec(i,result,ans,candidates,target);
            result.pop_back();
            target += candidates[i];
        }
        rec(i+1,result,ans,candidates,target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> result;
        rec(0,result,ans,candidates,target);
        return ans;
    }
};