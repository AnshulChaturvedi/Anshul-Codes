#define ll long long
#include<bits/stdc++.h>
using namespace std;

int main() {
    ll n; cin >> n;
    ll actualSum = (n*(n+1))/2;
    ll sum = 0;
    for(int i=1;i<n;i++){
        ll x ; cin >> x;
        sum += x;
    }
    cout << actualSum-sum;
}