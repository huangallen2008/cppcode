#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,(n)+1)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.clssize())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define Graph vector<vector<int>>
#define md(x) (x%mod+mod)%mod
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int inf=(1ll<<62);
const int maxn=1e5+5;
const int mod=1e9+7;
struct matrix {
    vector<vector<int>> a;
    matrix(int n,int m) {
        a=vector<vector<int>>(n,vector<int>(m));
    }
    matrix operator*(matrix b) const {
        int n=a.size(),m=b.a[0].size();
        matrix c(n,m);
        REP(i,n) {
            REP(j,m) {
                REP(k,b.a.size()) c.a[i][j]=md(c.a[i][j]+a[i][k]*b.a[k][j]);
            }
        }
        return c;
    }
};
matrix pw(matrix x,int p) {
    int n=x.a.size();
    matrix r(n,n);
    REP(i,n) r.a[i][i]=1;
    while(p>0) {
        if(p&1) r=r*x;
        x=x*x;
        p>>=1;
    }
    return r;
}
main() {
    IOS();
    int t;
    cin>>t;
    matrix x(3,3),z(1,3);
    x.a={{0,1,0},{1,1,1},{2,0,1}};
    z.a={{1,0,0}};
    cout<<(z*pw(x,t)).a[0][0]<<"\n";
    return 0;
}
