class Solution {
private:
    int memo[1001][101][101];
    int solve(int i,int m,int n,vector<string> &strs){
        if(i >= strs.size() || m<0 || n<0){
            return 0;
        }
        if(memo[i][m][n] != -1){
            return memo[i][m][n];
        }

        int noOfZeros = count(strs[i].begin(),strs[i].end(),'0');
        int noOfOnes = count(strs[i].begin(),strs[i].end(),'1');

        int pick = 0;
        if(noOfZeros <= m && noOfOnes <= n){
            pick = solve(i+1,m-noOfZeros,n-noOfOnes,strs) + 1;
        }
        int notPick = solve(i+1,m,n,strs);
        return memo[i][m][n] = max(pick,notPick);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(memo,-1,sizeof(memo));
        return solve(0,m,n,strs);
    }
};