#include<bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,n) for(int i=0;i<n;i++)
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
const int mod=1e9+7;
#define Matrix vector<vector<int>>
Matrix operator*(Matrix a,Matrix b) {
    int n=a.size(),m=b.size(),k=b[0].size();
    Matrix c(n,vector<int>(k));
    REP(i,n) REP(j,m) REP(l,k) c[i][l]=(c[i][l]+a[i][j]*b[j][l])%mod;
    return c;
}
Matrix pw(Matrix x,int p) {
    int n=SZ(x);
    Matrix r(n,vector<int>(n));
    REP(i,n) r[i][i]=1;
    while(p>0) {
        if(p&1) r=r*x;
        x=x*x;
        p>>=1;
    }
    return r;
}
void solve() {
    int n;
    cin>>n;
    Matrix x={{2,2}},r={{0,1},{1,1}};
    x=x*pw(r,n-1);
    int an=(x[0][0]%mod+mod)%mod;
    cout<<an<<'\n';
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}


