#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,sse4,abm,bmi,bmi2,popcnt,lzcnt")
// #define int long long
#define ll long long
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
void solve() {
    int n;
    cin>>n;
    int now=0;
    ll s=0,an=0;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=1;i<1<<n;i++) {
        int j=i&-i;
        if(now&j) s-=a[__builtin_ctz(i)];
        else s+=a[__builtin_ctz(i)];
        now^=j;
        an^=s;
    }
    cout<<an<<'\n';
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}