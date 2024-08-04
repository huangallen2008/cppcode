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
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct DSU {
    vector<int> p,sz;
    vector<pii> stk;
    int n;
    int cc;
    void init(int _n) {
        n=_n;
        stk.clear();
        p=vector<int>(n);
        sz=vector<int>(n,1);
        REP(i,n) p[i]=i;
        cc=0;
    }
    int find(int u) {
        return p[u]==u?u:find(p[u]);
    }
    void merge(int a,int b) {
        int x=find(a),y=find(b);
        if(x==y) return;
        p[x]=y;
        sz[y]+=sz[x];
        cc++;
        stk.pb({x,y});
    }
    void save() {
        stk.pb({-1,-1});
    }
    void revert() {
        while(stk.size()&&stk.back().f!=-1) {
            auto [x,y]:stk.back();
            stk.pop_back();
            sz[y]-=sz[x];
            p[x]=x;
            cc--;
        }
    }
}dsu;
struct SEG {
    vector<vector<pii>> s;
    DSU dsu;
    vector<int> an;
    void init(int n,int q) {
        s=vector<vector<pii>>(q<<2);
        dsu.init(n);
        an=vector<int>(q);
    }
    void ud(int w,int l,int r,int ql,int qr,int u,int v) {
        if(ql<=l&&r<=qr) {
            s[i].pb({u,v});
            return;
        }
        if(ql>r||qr<l) return;
        int m=l+r>>1;
        ud(w<<1,l,m,ql,qr,u,v);
        ud(w<<1|1,m+1,r,ql,qr,u,v);
    }
    void dfs(int w,int l,int r) {
        dsu.save();
        for(auto [u,v]:s[w]) dsu.merge(u,v);
        if(l==r) {
            an[l]=dsu.cc;
            dsu.revert();
            return;
        }
        int m=l+r>>1;
        dfs(w<<1,l,m);
        dfs(w<<1|1,m+1,r);
        dsu.revert();
        return;
    }
}seg;
signed main() {
    IOS();
    int n,m,k;
    cin>>n>>m>>k;
    int q=m+k;
    unordered_map<pii,int> mp;
    REP(i,m) {
        int u,v;
        cin>>u>>v;
        u--,v--;

    }
    return 0;
}