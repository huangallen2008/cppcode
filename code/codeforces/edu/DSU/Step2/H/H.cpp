#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,bmi,popcnt")
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
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";for(auto &allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=1e4+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct edge {
    int u,v,w,id;
};
struct DSU {
    vector<int> p,sz;
    int n,v=0;
    void init(int _n) {
        n=_n;
        p=vector<int>(n);
        sz=vector<int>(n,1);
        REP(i,n) p[i]=i;
        v=0;
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
    bool merge(edge e) {
        return merge(e.u,e.v);
    }
}dsu;
bool so(edge a,edge b) {
    return a.w>b.w;
}
signed main() {
    IOS();
    int n,m,s;
    cin>>n>>m>>s;
    dsu.init(n);
    vector<edge> e;
    REP(i,m) {
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        e.pb({u,v,w,i+1});
    }
    sort(ALL(e),so);
    vector<bool> used(m);
    REP(i,m) used[i]=dsu.merge(e[i]);
    int cnt=0,now=0;
    vector<int> an;
    RREP(i,m) {
        if(used[i]||now+e[i].w>s) continue;
        cnt++,now+=e[i].w;
        an.pb(e[i].id);
    }
    cout<<cnt<<'\n';
    for(int x:an) cout<<x<<' ';
    cout<<'\n';
    return 0;
}