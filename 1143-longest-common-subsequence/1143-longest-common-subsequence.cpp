class Solution {
private:
    int solve(int i,int j,string &text1,string &text2,vector<vector<int>> &memo){
        if(i>=text1.size() || j>=text2.size()){
            return memo[i][j] = 0;
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }

        if(text1[i] == text2[j]){
            return memo[i][j] = 1 + solve(i+1,j+1,text1,text2,memo);
        }
        int left = solve(i+1,j,text1,text2,memo);
        int right = solve(i,j+1,text1,text2,memo);
        return memo[i][j] =  max(left,right);
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> memo(n+1,vector<int> (m+1,-1));
        return solve(0,0,text1,text2,memo);
    }
};