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
const int maxn=1e7+5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct edge {
    int u,v;
};
struct DSU {
    Vi p,sz,d;
    vector<pii> stk;
    bool is_bip;
    void init(int n) {
        p=d=Vi(n);
        sz=Vi(n,1);
        REP(i,n) p[i]=i;
        stk.clear();
        is_bip=1;
    }
    pii find(int u) {
        if(p[u]==u) return {u,0};
        pii ret=find(p[u]);
        ret.s^=d[u];
        return ret;
    }
    void merge(int a,int b) {
        auto [x,dx]=find(a);
        auto [y,dy]=find(b);
        if(x==y) {
            if(dx^dy!=1) {
                is_bip=0;
                stk.pb({-2,-2});
            }
            return;
        }
        if(sz[x]>sz[y]) swap(x,y);
        p[x]=y;
        sz[y]+=sz[x];
        d[x]=dy^dx^1;
        stk.pb({x,y});
    }
    void merge(edge x) {
        merge(x.u,x.v);
    }
    void save() {
        stk.pb({-1,-1});
    }
    void rev() {
        while(stk.size()&&stk.back().f!=-1) {
            auto [x,y]=stk.back();
            stk.pop_back();
            if(x==-2) is_bip=1;
            else {
                p[x]=x;
                sz[y]-=sz[x];
                d[x]=0;
            }
        }
        if(stk.size()) stk.pop_back();
    }
    bool an() { return is_bip; }
};
struct TSEG {
    vector<vector<edge>> s;
    int n;
    Vi an;
    DSU dsu;
    void init(int _n) {
        n=_n;
        an=Vi(n);
        s=vector<vector<edge>>(n<<2);
    }
    void _ud(int w,int l,int r,int ql,int qr,edge e) {
        if(ql<=l&&r<=qr) {
            s[w].pb(e);
            return;
        }
        if(ql>r||qr<l) return;
        int m=l+r>>1;
        _ud(w<<1,l,m,ql,qr,e);
        _ud(w<<1|1,m+1,r,ql,qr,e);
    }
    void ud(int l,int r,edge e) {
        _ud(1,0,n-1,l,r,e);
    }
    void _run(int w,int l,int r) {
        dsu.save();
        for(auto e:s[w]) dsu.merge(e);
        if(l==r) {
            an[l]=dsu.an();
            dsu.rev();
            return;
        }
        int m=l+r>>1;
        _run(w<<1,l,m);
        _run(w<<1|1,m+1,r);
        dsu.rev();
    }
    void run() {
        dsu.init(n);
        _run(1,0,n-1);
    }
    Vi get_an() { return an; }
}tseg;
int n,q;
int id(edge e) {
    return e.u*n+e.v;
}
signed main() {
    IOS(); 
    cin>>n>>q;
    tseg.init(q+1);
    unordered_map<int,int> las;
    vector<edge> es;
    REP1(i,q) {
        edge e;
        cin>>e.u>>e.v,e.u--,e.v--;
        es.pb(e);
        int t=id(e);
        if(las[t]==0) {
            las[t]=i;
        }
        else {
            tseg.ud(las[t],i-1,e);
            las[t]=0;
        }
    }
    for(auto e:es) {
        int tt=las[id(e)];
        if(tt!=0) {
            tseg.ud(tt,q,e);
        }
    }
    tseg.run();
    Vi an=tseg.get_an();
    REP1(i,q) {
        if(an[i]) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}