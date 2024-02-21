#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define push_back pb
#include<bits/stdc++.h>
using namespace std;

int main() {
    ll t; cin >> t;
    while(t--) {
        ll n,s; cin >> n >> s;
        vector<ll> v;
        for(ll i=0;i<n;i++){
            ll x; cin >> x;
            v.push_back(x);
        }
        ll sum=0,cnt=0;
        sort(v.begin(),v.end());
        for(ll i=0;i<v.size();i++){
            auto it = v[i];
            sum += it;
            if(sum >= s) break;
            else{
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}