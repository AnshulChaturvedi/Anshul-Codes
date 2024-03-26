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
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (j <= i) {
                dp[i] += dp[i - j];
                dp[i] %= M;
            }
        }
    }
    cout << dp[n] << endl;
}