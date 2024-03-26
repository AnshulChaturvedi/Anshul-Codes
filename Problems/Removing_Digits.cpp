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
    int steps = 0;
    while(n>0){
        string s = to_string(n);
        int ans = 0;
        for(int i=0;i<s.length();i++){
            int c = s[i] - '0';
            ans = max(ans,c);
        }
        n = n-ans;
        steps++;
    }
    cout << steps << endl;
}