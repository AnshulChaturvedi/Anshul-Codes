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
    
    int n, x;
    cin >> n >> x;
    
    vector<int> cost(n + 1);
    vector<int> pages(n + 1);
    
    for(int i = 1; i <= n; i++) {
        cin >> cost[i];
    }
    
    for(int i = 1; i <= n; i++) {
        cin >> pages[i];
    }
    
    vector<int> dp(x + 1, 0);
    
    // dp[i] = maxi pages such that the total cost is less equal to i
    
    for(int i = 1; i <= n; i++) {
        for(int j = x; j >= cost[i]; j--) {
            dp[j] = max(dp[j], dp[j - cost[i]] + pages[i]);
        }
    }
    
    cout << dp[x] << endl;
    
    return 0;
}
