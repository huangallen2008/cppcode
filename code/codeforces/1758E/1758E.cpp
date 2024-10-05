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
#define oparr(x) cout<<(#x)<<":";REP(allen,(x).size()) cout<<x[allen]<<" ";cout<<" size="<<(x).size()<<endl;
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
    int n;
    int cnt;
    vector<int> p,sz;
    void init(int _n) {
        n=_n;
        cnt=n;
        p=vector<int>(n);
        sz=vector<int>(n,1);
        REP(i,n) p[i]=i;
    }
    int find(int u) {
        if(p[u]==u) return u;
        return p[u]=find(p[u]);
    }
    void merge(int a,int b) {
        int x=find(a),y=find(b);
        if(x==y) return;
        if(sz[x]>sz[y]) swap(x,y);
        p[x]=y;
        sz[y]+=sz[x];
        cnt--;
    }
    int get_an() { return cnt; }
}dsu;
int pw(int x,int p) {
    int r=1;
    while(p>0) {
        if(p&1) {
            r*=x;r%=mod;
        }
        x*=x;
        x%=mod;
        p>>=1;
    }
    return r;
}
#define MD(x,m) ((((x)%(m))+(m))%(m))
Graphw g;
int n,m,h;
vector<int> col;
bool dfs(int u) {
    for(auto [v,w]:g[u]) {
        if(col[v]!=-1) {
            if(MD(col[v]+col[u],h)!=w) return 0;
            continue;
        }
        col[v]=MD(w-col[u],h);
        if(!dfs(v)) return 0;
    }
    return 1;
}
void solve() {
    cin>>n>>m>>h;
    dsu.init(n+m);
    g=Graphw(n+m);
    col=vector<int>(n+m,-1);
    REP(i,n) {
        REP(j,m) {
            int v;
            cin>>v;
            if(v!=-1) {
                v=MD(h-v,h);
                dsu.merge(i,n+j);
                g[i].pb({n+j,v});
                g[n+j].pb({i,v});
            }
        }
    }
    REP(i,n+m) {
        if(col[i]==-1) {
            col[i]=0;
            if(!dfs(i)) {
                cout<<"0\n";
                return ;
            }
        }
    }
    int an=pw(h,dsu.get_an()-1);
    cout<<an<<'\n';
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
