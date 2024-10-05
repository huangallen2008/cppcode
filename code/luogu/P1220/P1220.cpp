#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
#define int long long
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<=(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) (int)((x).size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define Graphw vector<vector<pii>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#define MD(x,M) (((x)%(M)+(M))%(M))
#define ld long double
#define pdd pair<ld,ld>
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define addmod(x,y) x=((x+(y))%mod)
#define Vi vector<int>
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";for(auto &mken:(x)) cout<<mken<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=998244353;
const int maxn=1e8+5;
const int inf=(1ll<<61);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();
    int n,c;
    cin>>n>>c;
    Vi x(n+1),w(n+1),p(n+1);
    REP1(i,n) cin>>x[i]>>w[i];
    REP1(i,n) p[i]=p[i-1]+w[i];
    vector<Vi> dpl(n+1,Vi(n+1,inf));
    vector<Vi> dpr(n+1,Vi(n+1,inf));
    dpl[c][c]=0;
    dpr[c][c]=0;
    REP1(r,n) {
        for(int l=r-1;l>=1;l--) {
            chmin(dpl[l][r],dpr[l][r-1]+(p[n]-p[r]+p[l-1])*(x[r]-x[l]+x[r]-x[r-1])+w[r]*(x[r]-x[r-1]));//x_l->x_r->x_r-1
            chmin(dpl[l][r],dpl[l+1][r]+(p[n]-p[r]+p[l])*(x[l+1]-x[l]));//x_l->x_r->x_l
            chmin(dpr[l][r],dpl[l+1][r]+(p[n]-p[r]+p[l-1])*(x[r]-x[l]+x[l+1]-x[l])+w[l]*(x[l+1]-x[l]));//x_l->x_r->x_r-1
            chmin(dpr[l][r],dpr[l][r-1]+(p[n]-p[r-1]+p[l-1])*(x[r]-x[r-1]));//x_l->x_r->x_l
        }
    }
    int an=min(dpl[1][n],dpr[1][n]);
    cout<<an<<'\n';
    return 0;
}