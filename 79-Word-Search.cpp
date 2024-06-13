class Solution {
public:
    int n,m;
    vector<vector<int>> del{{1,0},{-1,0},{0,1},{0,-1}};

    bool find(int r,int c,string &word,vector<vector<char>>& board,int idx){
        if(idx >= word.size()){
            return true;
        }
        if(r<0 || c<0 || r>=n || c>=m || board[r][c] == '$' || word[idx] != board[r][c]){
            return false;
        }

        auto temp = board[r][c];
        board[r][c] = '$'; //marks as visited

        for(auto &it : del){
            int nrow = r + it[0];
            int ncol = c + it[1];
            if(find(nrow,ncol,word,board,idx+1)){
                return true;
            }
        }

        board[r][c] = temp;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[0] && find(i,j,word,board,0)){
                    return true;
                }
            }
        }
        return false;
    }
};