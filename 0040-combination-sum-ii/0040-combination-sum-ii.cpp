class Solution {
private:
    void solve(int i,vector<vector<int>> &ans,vector<int> result,int target,
                    vector<int> &candidates,int &n){
                
            if(target < 0){
                return;
            }
            if(target == 0){
                ans.push_back(result);
                return;
            }
            
            for(int j=i;j<n;j++){
                if(j>i && candidates[j] == candidates[j-1]) continue;
                result.push_back(candidates[j]);
                solve(j+1,ans,result,target-candidates[j],candidates,n);
                result.pop_back();
            }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();

        sort(candidates.begin(),candidates.end());

        vector<vector<int>> ans;
        vector<int> result;
        solve(0,ans,result,target,candidates,n);
        return ans;
    }
};