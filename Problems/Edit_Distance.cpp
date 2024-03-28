#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define inf INT_MAX
#define _inf INT_MIN
#define endl '\n'

const int M = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string str1,str2; cin >> str1 >> str2;
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    // dp[i][j] = min no. of operations to transform str1(0....i-1) into str2(0....j-1)
    // i and j represent the length of the str1 and str2 respectively
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i == 0){
                dp[i][j] = j;
            }
            else if(j == 0){
                dp[i][j] = i;
            }
            else if(str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                /*3 operations
                  replace = op(1) + (str1[i-1],str2[j-1])
                  delete = op(1) + (str1[i-1],str2[j])
                  add = op(1) + (str1[i],str2[j-1]) 
                */

                dp[i][j] = min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j])) + 1;
            }
        }
    }
    cout << dp[n][m] << endl;
}