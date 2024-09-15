#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,(n)+1)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) ((x%(mod)+(mod))%(mod))
#ifdef local
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int inf=(1ll<<62);
const int maxn=1e5+5;
const int mod=1e9+7;
struct Matrix {
    vector<vector<int>> v;
    void init(int n,int m) {
        v=vector<vector<int>>(n,vector<int>(m));
    }
    Matrix operator*(Matrix p) {
        int n=v.size(),m=p.v.size(),k=p.v[0].size();
        vector<vector<int>> r(n,vector<int>(k));
        REP(i,n) {
            REP(j,k) {
                REP(l,m) {
                    r[i][j]=md(r[i][j]+v[i][l]*p.v[l][j]);
                }
            }
        }
        Matrix mm;
        mm.v=r;
        return mm;
    }
};
Matrix pw(Matrix x,int p) {
    Matrix r;
    r.init(x.v.size(),x.v.size());
    REP(i,x.v.size()) r.v[i][i]=1;
    while(p>0) {
        if(p&1) r=r*x;
        x=x*x;
        p>>=1;
    }
    return r;
}
signed main() {
    IOS();
    int p,q,r;
    cin>>p>>q>>r;
    int a1,a0;
    cin>>a0>>a1;
    Matrix m;
    m.v={{a1,a0,r}};
    Matrix rr;
    rr.v={{p,1,0},{q,0,0},{1,0,1}};
    int T;
    cin>>T;

    while(T--) {
            int n;
    cin>>n;
        Matrix mm;
        mm.v=m.v;
        mm=mm*pw(rr,n);
        cout<<mm.v[0][1]<<'\n';
    }
    return 0;
}
