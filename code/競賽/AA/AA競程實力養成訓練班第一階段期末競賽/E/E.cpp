#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,popcnt")
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
int n,m;
Graphw g;
vector<bool> inc,incy;
vector<int> an;
vector<pii> edge;
void bfs(int st) {
    queue<int> q;
    q.push(st);
    vector<int> dis(n,inf),pre(n,-1),pid(n,-1);
    vector<bool> vis(n);
    dis[st]=0;
    while(q.size()) {
        int u=q.front();
        q.pop();
        for(auto [v,w]:g[u]) {
            if(v==pre[u]) continue;
            if(dis[v]!=inf) {
                int t=u;
                while(t!=st) {
                    incy[t]=1;
                    int id=pid[t];
                    an[id]=edge[id].f==t;
                    t=pre[t];
                }
                t=v;
                while(t!=st) {
                    incy[t]=1;
                    int id=pid[t];
                    an[id]=edge[id].s==t;
                    t=pre[t];
                }
                incy[st]=1;
                an[w]=edge[w].f==v;
                return;
            }
            dis[v]=dis[u]+1;
            pre[v]=u;
            pid[v]=w;
            q.push(v);
        }
    }
}
vector<bool> vis;
vector<int> dep;
void dfs(int u,int p) {
    vis[u]=1;
    for(auto [v,id]:g[u]) {
        if(v==p) continue;
        if(incy[v])continue;
        if(vis[v]) {
            if(dep[v]>dep[u]) an[id]=edge[id].f==u;
            continue;
        }
        an[id]=edge[id].f==u;
        dep[v]=dep[u]+1;
        dfs(v,u);
    }
}
signed main() {
    IOS();
    cin>>n>>m;
    g=Graphw(n);
    an=vector<int>(m,-1);
    incy=vector<bool>(n);
    vector<int> deg(n);
    REP(i,m) {
        int u,v;
        cin>>u>>v;
        g[u].pb({v,i});
        g[v].pb({u,i});
        deg[u]++,deg[v]++;
        edge.pb({u,v});
    }
    inc=vector<bool>(n,1);
    queue<int> q;
    REP(i,n) if(deg[i]==1) q.push(i);
    while(q.size()) {
        int u=q.front();
        inc[u]=0;
        q.pop();
        for(auto [v,w]:g[u]) {
            deg[v]--;
            if(deg[v]==1) {
                q.push(v);
            }
        }
    }
    vis=vector<bool>(n);
    dep=vector<int>(n,-1);
    REP(i,n) {
        if(inc[i]) {
            bfs(i);
            break;
        }
    }
    REP(i,n) {
        if(incy[i]) {
            dep[i]=0;
            dfs(i,-1);
        }
    }
    REP(i,m) cout<<an[i];
    cout<<'\n';
    return 0;
}