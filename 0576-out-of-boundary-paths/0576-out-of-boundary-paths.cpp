class Solution {
private:
    int delr[4] = {0,+1,0,-1};
    int delc[4] = {+1,0,-1,0};
    const int MOD = 1e9 + 7;
    int dp[51][51][51];

    int solve(int m,int n,int move,int r,int c){
        if(r < 0 || c < 0 || r >= m ||c >= n){
            return 1;
        }
        if(move <= 0) return 0;

        if(dp[r][c][move] != -1) return dp[r][c][move];

        int cnt = 0;
        for(int i=0;i<4;i++){
            int nrow = r + delr[i];
            int ncol = c + delc[i];
            cnt = (cnt%MOD + solve(m,n,move-1,nrow,ncol)%MOD)%MOD;
        }
        return dp[r][c][move] = cnt;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return solve(m,n,maxMove,startRow,startColumn);
    }
};