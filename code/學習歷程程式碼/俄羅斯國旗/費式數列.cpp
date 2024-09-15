#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
const int mod=1e9+7;
const int maxn=2e5+5;
vector<int> f(maxn);
void init() {
    f[0]=0,f[1]=1;
    for(int i=2;i<maxn;i++) f[i]=(f[i-1]+f[i-2])%mod;
}
void solve() {
    int n;
    cin>>n;
    int an=((f[n]<<1)%mod+mod)%mod;
    cout<<an<<'\n';
}
signed main() {
    IOS();
    inti();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}






