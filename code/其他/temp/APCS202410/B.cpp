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
const int maxn=5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
vector<pii> dir={{0,1},{1,0},{0,-1},{-1,0}};
pii p;
int n,m,k;
vector<Vi> a;
bool ok(pii x) {
    if(x.f<0||x.f>=n||x.s<0||x.s>=m||a[x.f][x.s]==-1) return 0;
    return 1;
}
pii nxt(pii x,int dd)   {
    return {x.f+dir[dd].f,x.s+dir[dd].s};
}
int nd=0;
signed main() {
    IOS(); 
    cin>>n>>m>>k>>p.f>>p.s;
    a=vector<Vi>(n,Vi(m));
    REP(i,n) REP(j,m) cin>>a[i][j];
    int sc=0,an=0;
    while(1) {
        if(a[p.f][p.s]==0) break;
        sc+=a[p.f][p.s]--;
        an++;
        if(sc%k==0) nd=(nd+1)%4;
        while(!ok(nxt(p,nd))) nd=(nd+1)%4;
        p=nxt(p,nd);
    }
    cout<<an<<'\n';
    return 0;
}