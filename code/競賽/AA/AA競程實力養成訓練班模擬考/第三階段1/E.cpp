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
struct edge {
    int u,v,w;
};
struct DSU {
    int n;
    int an=0;
    Vi p,sz;
    void init(int _n) {
        n=_n;
        an=0;
        p=Vi(n);
        sz=Vi(n,1);
        REP(i,n )p[i]=i;
    }
    int find(int u) {
        return p[u]==u?u:p[u]=find(p[u]);
    }
    bool merge(int a,int b) {
        int x=find(a),y=find(b);
        if(x==y) return 0;
        if(sz[x]>sz[y]) swap(x,y);
        p[x]=y;
        sz[y]+=sz[x];
        return 1;
    }
    void merge(edge e) {
        if(merge(e.u,e.v)) an+=e.w;
    }
}dsu;
signed main() {
    IOS(); 
    int n,m;
    cin>>n>>m;
    Vi w(m);
    REP(i,m) cin>>w[i];
    vector<Vi> a(m);
    REP(i,n) {
        int k;
        cin>>k;
        REP(j,k) {
            int id;
            cin>>id,id--;
            a[id].pb(i);
        }
    }
    dsu.init(n);
    vector<pii> t(m);
    REP(i,m) t[i]={w[i],i};
    sort(ALL(t));
    int an=0;
    for(auto [x,id]:t) {
        an+=x*(SZ(a[id])*(SZ(a[id])-1)>>1);
        REP1(i,SZ(a[id])-1) {
            dsu.merge({a[id][i-1],a[id][i],x});
        }
    }
    an-=dsu.an;
    cout<<an<<'\n';
    return 0;
}