#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define push_back pb
#include<bits/stdc++.h>
using namespace std;

int main() {
    ll t; cin >> t;
    while(t--) {
        ll y,x; cin >> y >> x;
        ll z = max(y,x), ans;
        ll z2 = (z-1)*(z-1);
        
        if(z%2){
            if(y==z){
                ans = z2 + x;
            }else{
                ans = z2+2*z-y;
            }
        }else{
            if(x==z){
                ans = z2+y;
            }else{
                ans = z2+2*z-x;
            }
        }
        cout << ans << endl;
    }
}