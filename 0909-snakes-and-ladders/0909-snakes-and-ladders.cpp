class Solution {
public:
    pair<int,int> getCoordinates(int val,int n){
        int row_from_top = (val-1)/n;
        int row_from_bottom = (n-1) - row_from_top;
        int col = (val-1)%n;
        if((n%2==0 && row_from_bottom%2==0) || (n%2==1 && row_from_bottom%2==1)){
            col = (n-1)-col;
        }
        return {row_from_bottom,col};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        int steps = 0;

        queue<int> q;
        q.push(1);
        vector<vector<bool>> vis(n,vector<bool> (n,false));
        vis[n-1][0] = true;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                int x = q.front();
                q.pop();
                if(x == n*n){
                    return steps;
                }
                for(int k=1;k<=6;k++){
                    int val = x+k;
                    if(val > n*n){
                        break;
                    }
                    pair<int,int> coordinates = getCoordinates(val,n);
                    int r = coordinates.first;
                    int c = coordinates.second;

                    if(vis[r][c] == true) continue;
                    vis[r][c] = true;

                    if(board[r][c] == -1){
                        q.push(val);
                    }
                    else{
                        q.push(board[r][c]);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};