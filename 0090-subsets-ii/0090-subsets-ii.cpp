class Solution {
private:
    void solve(int i,vector<int> result,set<vector<int>> &ans,vector<int>& nums,int n){
        if(i==n){
            ans.insert(result);
            return;
        }
        result.push_back(nums[i]);
        solve(i+1,result,ans,nums,n);
        result.pop_back();
        solve(i+1,result,ans,nums,n);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        vector<int> result;
        solve(0,result,ans,nums,n);
        vector<vector<int>> temp(ans.begin(),ans.end());
        return temp;
    }
};