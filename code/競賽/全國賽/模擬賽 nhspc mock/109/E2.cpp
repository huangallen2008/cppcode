#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi2,popcnt")
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
#define oparr(x) cout<<(#x)<<":";for(auto allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
template<typename T1,typename T2>
ostream& operator<<(ostream& os,pair<T1,T2> p) { return os<<'{'<<p.f<<','<<p.s<<'}'; }
const int mod=1e9+7;
const int maxn=5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n1,n2;
Vi t1,t2;
Graph g1,g2,g;
Vi mxd,dia,vis;
bool ok=1;
void dfs(int u,int fa,Graph& g) {
    int mx1=0,mx2=0;
    vis[u]=1;
    for(int v:g[u]) {
        if(v==fa) continue;
        if(vis[v]) {
            ok=0;
            return;
        }
        dfs(v,u,g);
        int val=mxd[v]+1;
        chmax(mxd[u],val);
        if(val>mx1) mx2=mx1,mx1=val;
        else if(val>mx2) mx2=val;
    }
    chmax(dia[u],mx1+mx2);
}
int diam(int n,Graph &g) {
    mxd=dia=vis=Vi(n);
    ok=1;
    dfs(0,-1,g);
    return ok?dia[0]:-1;
}
signed main() {
    IOS();
    cin>>n1;
    t1=Vi(n1);
    g1=Graph(n1);
    REP(i,n1) cin>>t1[i];
    REP(i,n1) {
        REP(j,n1) {
            char c;
            cin>>c;
            if(c=='1') g1[i].pb(j);
        }
    }
    cin>>n2;
    t2=Vi(n2);
    g2=Graph(n2);
    REP(i,n2) cin>>t2[i];
    REP(i,n2) {
        REP(j,n2) {
            char c;
            cin>>c;
            if(c=='1') g2[i].pb(j);
        }
    }
    g=Graph(n1*n2);
    auto tid=[&](int a,int b) { return a*n2+b; };
    REP(u1,n1) {
        REP(u2,n2) {
            if(t1[u1]!=t2[u2]) continue;
            REP(v1,n1) if(v1!=u1) {
                REP(v2,n2) if(u2!=v2) {
                    if(t1[v1]!=t2[v2]) continue;
                    g[tid(u1,u2)].pb(tid(u2,v2));
                }
            }
        }
    }
    int ret=diam(n1*n2,g);
    if(ret==-1) cout<<"INF\n";
    else cout<<ret<<'\n';
    return 0;
}