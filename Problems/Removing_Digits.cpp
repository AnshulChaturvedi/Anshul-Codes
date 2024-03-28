#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define inf INT_MAX
#define endl '\n'

const int M = 1e9 + 7;


vector<int> getDigits(int n){
    vector<int> ans;
    while(n>0){
        int last = n%10;
        ans.pb(last);
        n /= 10;
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // int n; cin >> n;
    // int steps = 0;
    // while(n>0){
    //     string s = to_string(n);
    //     int ans = 0;
    //     for(int i=0;i<s.length();i++){
    //         int c = s[i] - '0';
    //         ans = max(ans,c);
    //     }
    //     n = n-ans;
    //     steps++;
    // }
    // cout << steps << endl;

    int n ; cin >> n;
    vector<int> dp(n+1,inf);
    // dp[i] = mini no. of steps req to make i equal to zero
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        vector<int> v = getDigits(i);
        for(int j=0;j<v.size();j++){
            if(v[j] != 0){
                dp[i] = min(dp[i],dp[i-v[j]]+1);
            }
        }
    }
    cout << dp[n] << endl;
}