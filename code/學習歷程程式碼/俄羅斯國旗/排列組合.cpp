#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
const int mod=1e9+7;
const int maxn=2e5+5;
int pw(int x,int p) {
    int r=1;
    while(p>0) {
        if(p&1) r*=x,r%=mod;
        x*=x,x%=mod;
        p>>=1;
    }
    return r;
}
int inv(int x) {
    return pw(x,mod-2);
}
vector<int> fac(maxn),infac(maxn);
void init() {
    fac[0]=1,infac[0]=1;
    for(int i=1;i<maxn;i++) fac[i]=fac[i-1]*i%mod; 
    for(int i=1;i<maxn;i++) infac[i]=inv(fac[i]); 
}
int C(int n,int k) { 
    return (fac[n]*infac[n-k]%mod)*infac[k]%mod;
}
void solve() {
    int n;
    cin>>n;
    int an=0;
    for(int i=0;i<(n-1>>1);i++) {
        an=(an+C(n-i-1,i))%mod;
    }
    an=((an<<1)%mod+mod)%mod;
    cout<<an<<'\n';
}
signed main() {
    IOS();
    init();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}

