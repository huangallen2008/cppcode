#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Vi vector<int> 
#define REP(i,n) for(int i=0;i<n;i++)
const int mod=998244353;
int pw(int x,int p) {
    int r=1;
    while(p>0) {
        if(p&1) r=r*x%mod;
        x=x*x%mod;
        p>>=1;
    }
    return r;
}
signed main() {
    int n,m;
    cin>>n>>m;
    m--;
    while(((n%4!=0)||(n%8==0))&&m>0){
        int mnf=n;
        for(int i=2;i*i<=n;i++) if(n%i==0) {  mnf=i; break;}
        n=n+n/mnf;
        m--;
    }
    if(m==0) {
        cout<<n%mod<<'\n';
        return 0;
    }
    n/=4;
    n%=mod;
    int tt=m/3;
    Vi rr={4,6,9};
    int an=n*rr[m%3]%mod*pw(3,tt)%mod;
    an=(an%mod+mod)%mod;
    cout<<an<<'\n';
    return 0;
}
