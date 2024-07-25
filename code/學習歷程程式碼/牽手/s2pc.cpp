#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
const int mod=1e9+7;
const int maxn=1e6+5;
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
vector<int> fac(maxn<<1),infac(maxn<<1);
int C(int n) {
    return (fac[n<<1]*infac[n]%mod)*infac[n+1]%mod;
}
signed main() { 
    IOS();
    fac[0]=1,infac[0]=1;
    for(int i=1;i<maxn<<1;i++) 
        fac[i]=fac[i-1]*i%mod,infac[i]=inv(fac[i]);
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        cout<<C(n)<<'\n';
    }
    return 0;
}



