#include<bits/stdc++.h>
using namespace std;

void solve(string s){
    int n = s.length();
        vector<int> cnt(2,0);
        for(int i=0;i<n;i++){
            cnt[s[i] - '0']++;
        }
        for(int i=0;i<n;i++){
            int req = (s[i] - '0')^1;
            if(cnt[req] == 0){
                cout << n-i << endl;
                return;
            }
            cnt[req]--;
        }
        cout << 0 << endl;
}

int main() {
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        solve(s);
    }
}