//qwq QWQ
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
const int maxb=20;
const int sn=1300;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n,m;
Graph g;
vector<int> dep,dv,dfn;
int st[maxb][maxn<<1];
void st_init() {
    int n=dv.size();
    REP(i,n) st[0][i]=dv[i];
    REP1(i,maxb-1) {
        REP(j,n) {
            st[i][j]=min(st[i-1][j],st[i-1][min(n-1,j+(1<<i-1))]);
        }
    }
}
int lca_dep(int x,int y) { 
    int l=dfn[x],r=dfn[y];
    if(l>r) swap(l,r);
    int lg=__lg(r-l+1);
    return min(st[lg][l],st[lg][r-(1<<lg)+1]); 
}
int dis(int x,int y) {//O(1)
    return dep[x]+dep[y]-(lca_dep(x,y)<<1);
}
void dfs(int u,int pa) {
    dfn[u]=dv.size();
    dv.pb(dep[u]);
    for(int v:g[u]) {
        if(v==pa) continue;
        dep[v]=dep[u]+1;
        dfs(v,u);
        dv.pb(dep[u]);
    }
}
vector<int> d; 
vector<int> rn;
void bfs() {
    d=vector<int>(n,inf);
    queue<int> q;
    for(int &x:rn) q.push(x),d[x]=0;
    while(q.size()) {
        int u=q.front();
        q.pop();
        for(int v:g[u]) {
            if(d[v]<=d[u]+1) continue;
            d[v]=d[u]+1;
            q.push(v);
        }
    }
}
signed main() {
    IOS();
    cin>>n>>m;
    g=Graph(n);
    dep=dfn=vector<int>(n);
    REP(i,n-1) {
        int u,v;
        cin>>u>>v,u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0,-1);
    st_init();
    vector<int> t;
    t.pb(0);
    REP(i,m) {
        if(i%sn==0) {
            while(t.size()) {
                rn.pb(t.back());
                t.pop_back();
            }
            bfs();
        }
        int opt;
        cin>>opt;
        if(opt==1) {
            int u;
            cin>>u,u--;
            t.pb(u);
        }
        else {
            int u;
            cin>>u,u--;
            int an=d[u];
            for(int &x:t) chmin(an,dis(x,u));
            cout<<an<<'\n';
        }
    }
    return 0;
}