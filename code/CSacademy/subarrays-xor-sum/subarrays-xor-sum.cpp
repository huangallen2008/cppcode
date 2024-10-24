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
const int mod=1e9+7;
const int maxn=100+5;
const int maxx=2e5+5;
const int inf=(1<<25);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS(); 
    int n,L,R;
    cin>>n>>L>>R;
    Vi a(n+1);
    REP1(i,n) cin>>a[i];
    vector<Vi> x[2],p[2],px[2];
    x[0]=x[1]=p[0]=p[1]=px[0]=px[1]=vector<Vi>(30,Vi(n+1));
    REP1(i,n) {
        REP(j,30) x[0][j][i]=(a[i]>>j)&1,x[1][j][i]=x[0][j][i]^1,px[0][j][i]=px[0][j][i-1]^x[0][j][i],px[1][j][i]=px[1][j][i-1]^x[1][j][i],p[0][j][i]=p[0][j][i-1]+x[0][j][i],p[1][j][i]=p[1][j][i-1]+x[1][j][i];
    }
    int an=0;
    REP1(i,n) {
        REP(j,30) {
            int b=x[0][j][i-1];
            an+=p[b][j][min(i+R-1,n)]-p[b][j][min(i+L-2,n)]<<j;
            // if(j<7){op(i)ope(an)op(b)oparr(p[b][j])}
        }
        ope(an)
    }
    cout<<an<<'\n';
    return 0;
}