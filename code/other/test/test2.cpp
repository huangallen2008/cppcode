#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
const int mod=1e9+7;
signed main() {
    vector<int> f(maxn);
    f[1]=1;
    for(int i=2;i<maxn;i++) f[i]=(f[i-1]+f[i-2])%mod;
    int q;
    cin>>q;
    while(q--) {
        int n;
        cin>>n;
        cout<<f[n]<<' ';
    }
    cout<<'\n';
    return 0;
}