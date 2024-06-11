class Solution {
private:
    void solve(int open, int close,string result,vector<string> &ans, int n){
        if(close == n){
            ans.push_back(result);
            return;
        }
        if(open < n){
            solve(open+1,close,result+'(',ans,n);
        }
        if(close < open){
            solve(open,close+1,result+')',ans,n);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string result;
        solve(0,0,result,ans,n);
        return ans;
    }
};