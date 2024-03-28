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
    
    int n,sum; cin >> n >> sum;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin >> coins[i];
    }
    vector<int> dp(sum+1,INT_MAX);
    /// dp[i] = mini number of coins to make sum equal to i
    dp[0] = 0;
    for(int i=1;i<=sum;i++){
        for(int j=0;j<n;j++){
            if(coins[j]<=i){
                dp[i] = min(dp[i],1+dp[i-coins[j]]);
            }
        }
    }
    if(dp[sum] == INT_MAX){
        cout << -1 << endl;
    }else{
        cout << dp[sum] << endl;
    }
}