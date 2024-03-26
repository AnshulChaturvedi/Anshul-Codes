#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define endl '\n'

const int M = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n; cin >> n;
    vector<vector<char>> grid(n,vector<char> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> dp(n,vector<int> (n,0));
 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == '*'){
                dp[i][j] = 0;
            }
            else if(i == 0 && j == 0){
                dp[i][j] = 1;
            }
            else if(i == 0){
                dp[i][j] = dp[i][j-1];
            }
            else if(j == 0){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    cout << dp[n-1][n-1] << endl;
}