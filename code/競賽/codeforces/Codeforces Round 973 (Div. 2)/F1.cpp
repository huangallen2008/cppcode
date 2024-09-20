#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
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
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
Graph g;
int n;
Vi lev,dep,in,out;
int b;
int dfnc=0;
void dfs0(int u,int fa) {
    in[u]=dfnc++;
    for(int v:g[u]) {
        if(v==fa) continue;
        lev[v]=lev[u]+1;
        dfs0(v,u);
    }
    out[u]=dfnc++;
}
int ana,anb;
bool isa(int a,int b) { // if a is b's ancient
    return in[a]<=in[b]&&out[b]<=out[a];
}
void dfs(int u,int fa) {
    for(int v:g[u]) {
        if(v==fa) continue;
        dfs(v,u);
        // op(u)op(b)op(isa(u,b))ope(isa(b,u))
        if(isa(u,b)) {
            if(lev[u]<=(lev[b]>>1)) {
                chmax(ana,lev[u]);
                if(!isa(v,b)) chmax(ana,lev[v]+dep[v]);
            }
            else {
                if(!isa(v,b)&&v!=b) chmax(anb,lev[b]-lev[u]+dep[v]+1);
                else chmax(anb,lev[b]-lev[u]);
            }
        }
        if(isa(b,u)) {
            // op(anb)ope("wvefve")
            chmax(anb,lev[v]-lev[b]+dep[v]);
        }
        if(!isa(b,u)&&!isa(u,b)) {
            chmax(ana,lev[u]+dep[v]+1);
        }
        chmax(dep[u],dep[v]+1);
        // op(u)op(v)op(ana)ope(anb)
    }
}
void solve() {
    cin>>n;
    g=Graph(n);
    REP(i,n-1) {
        int u,v;
        cin>>u>>v,u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    cin>>b>>b,b--;
    if(b==0) {
        cout<<"Alice\n";
        return;
    }
    in=out=lev=dep=Vi(n);
    dfnc=0;
    dfs0(0,-1);
    ana=anb=0;
    dfs(0,-1);
    // op(ana)ope(anb)
    if(ana>=anb) {
        cout<<"Alice\n";
    }
    else cout<<"Bob\n";
    // ope(isa(b,1))
    // entr
}
signed main() {
    IOS(); 
    int T=1;
    cin>>T;
    while(T--) 
    solve();
    return 0;
}