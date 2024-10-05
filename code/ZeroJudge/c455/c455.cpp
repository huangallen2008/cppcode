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
const int inf=(1ll<<63)-1;
const int maxn=2e5+5;
const int mod=1e9+7;
struct edge {
    int u,v,cap,rest;
};
struct Dinic {
    int n,s,t;
    vector<vector<int>> g;
    vector<edge> edges;
    vector<int> d,cur;
    void init(int _n) {
        n=_n;
        edges.clear();
        g=vector<vector<int>>(n);
    }
    void add_edge(int u,int v,int cap) {
        edges.pb({u,v,cap,cap});
        edges.pb({v,u,0,0});
        int m=edges.size();
        g[u].pb(m-2);
        g[v].pb(m-1);
    }
    bool bfs() {
        d=vector<int>(n,-1);
        queue<int> q;
        d[s]=0;
        q.push(s);
        while(q.size()) {
            int u=q.front();
            q.pop();
            REP(i,g[u].size()) {
                int ei=g[u][i];
                auto [x,v,cap,rest]=edges[ei];
                if(d[v]<0&&rest>0) {
                    d[v]=d[u]+1;
                    q.push(v);
                }
            }
        }
        return d[t]>=0;
    }
    int dfs(int u,int a) {
        if(a==0||u==t) return a;
        int an=0;
        for(int &i=cur[u];i<g[u].size();i++) {
            int ei=g[u][i];
            auto [x,v,cap,rest]=edges[ei];
            if(d[v]!=d[u]+1) continue;
            int f=dfs(v,min(a,rest));
            if(f>0) {
                an+=f;
                edges[ei].rest-=f;
                edges[ei^1].rest+=f;
                a-=f;
                if(a==0) break;
            }
        }
        return an;
    }
    int max_flow(int _s,int _t) {
        s=_s; t=_t;
        int an=0;
        while(bfs()) {
            cur=vector<int>(n);
            int mf=dfs(s,inf);
            if(mf>0) an+=mf;
            else break;
        }
        return an;
    }
};
signed main()
{
    IOS();
    int T;
    cin>>T;
    while(T--) {
        Dinic F;
        int p,q,k;
        cin>>p>>q>>k;
        F.init(p+q+2);
        vector<int> x(p),y(q);
        int s=0,t=1;
        REP(i,p) x[i]=i+2;
        REP(i,q) y[i]=i+p+2;
        REP(i,k) {
            int u,v;
            cin>>u>>v;
            u--,v--;
            F.add_edge(x[u],y[v],1);
        }
        REP(i,p) F.add_edge(s,x[i],1);
        REP(i,q) F.add_edge(y[i],t,1);
        cout<<F.max_flow(s,t)<<"\n";
    }
    return 0;
}
/*
3
3 4 5
1 2
1 3
2 1
2 3
3 4
2 2 3
1 1
2 2
1 2
5 4 8
1 1
1 4
2 1
3 2
3 4
4 4
5 1
5 3


*/
