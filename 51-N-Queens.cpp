class Solution {
private:
    bool isValid(int row,int col,vector<string> &board,int n){
        //upwardValid
        for(int i=row-1;i>=0;i--){
            if(board[i][col] == 'Q'){
                return false;
            }
        }

        //upwardDiagLeft
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        //upwardDiagRight
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }

    void solve(int row,vector<string> &board,vector<vector<string>> &ans,int n){
        if(row >= n){
            ans.push_back(board);
            return;
        }
        for(int col = 0;col < n;col++){
            if(isValid(row,col,board,n)){
                board[row][col] = 'Q';
                solve(row+1,board,ans,n);
                board[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.')); //creates the board
        solve(0,board,ans,n);
        return ans;
    }
};