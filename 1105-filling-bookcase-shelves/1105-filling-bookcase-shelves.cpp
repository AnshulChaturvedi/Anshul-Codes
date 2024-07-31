class Solution {
public:
    int width;
    int dp[1001][1001];
    int solve(int i,vector<vector<int>>& books, int remW, int height){
        if(i >= books.size()){
            return height;
        }
        if(dp[i][remW] != -1) return dp[i][remW];
        int take = INT_MAX;
        if(books[i][0] <= remW){
            take = solve(i+1,books,remW-books[i][0],max(height,books[i][1]));
        }
        int skip = solve(i+1,books,width-books[i][0],books[i][1]) + height;
        return dp[i][remW] = min(take,skip);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        width = shelfWidth;
        memset(dp,-1,sizeof(dp));
        return solve(0,books,shelfWidth,0);
    }
};