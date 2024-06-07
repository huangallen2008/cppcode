#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,(n)+1)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int inf=(1ll<<62);
const int maxn=1e5+5;
const int mod=1e9+7;
struct edge {
    int u,v,cap,rest;
}
struct Dinic {
    int n,m;
    vector<edge> edges;
    Graph g;
    vector<int> d,cur;
    void init(int _n) {
        n=_n;
        edges.clear();
        g=Graph(n);
    }
    void add_edge(int u,int v,int cap) {
        edges.pb({u,v,cap,cap});
        edges.pb({v,u,0,0});
        m=edges.size();
        g[u].pb(m-2);
        g[v].pb(m-1);
    }
    bool bfs() {
        d=vector<int>(n,-1);
        queue<int> q;
        q.push(s);
        d[s]=0;
        while(q.size()) {
            int u=q.front();
            q.pop();
            REP(i,g[u].size()) {
                int ei=g[u][i];
                auto [x,v,cap,rest]=edges[ei];
                if(d[v]<0&&rest>0) d[v]=d[u]+1;
            }
        }
    }
    int dfs(int u,int a) {
        if(a==0) return a;
    }
    int max_flow(int _s,int _t) {
        s=_s; t=_t;
        while(bfs()) {
            int mf=dfs(s,inf);
        }
    }
}
signed main()
{
    IOS();
    int T;
    cin>>T;
    while(T--) {

    }
    return 0;
}
