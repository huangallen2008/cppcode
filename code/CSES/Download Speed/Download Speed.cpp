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
const int maxn=1e5+5;
const int mod=1e9+7;
struct edge {
    int u,v,cap,rest;
};
struct Dinic {
    int n,m,s,t;
    vector<edge> edges;
    vector<vector<int>> g;
    vector<int> d,cur;
    void init(int _n) {
        n=_n;
        g=vector<vector<int>>(n);
    }
    void addedge(int u,int v,int cap) {
        edges.pb({u,v,cap,cap});
        edges.pb({v,u,0,0});
        m=edges.size();
        g[u].pb(m-2);
        g[v].pb(m-1);
    }
    bool bfs() {
        queue<int> q;
        d=vector<int>(n,-1);
        q.push(s);
        d[s]=0;
        while(q.size()) {
            int u=q.front();
            q.pop();
            for(auto x:g[u]) {
                auto [y,v,cap,rest]=edges[x];
                if(d[v]<0&&rest>0) {
                    d[v]=d[u]+1;
                    q.push(v);
                }
            }
        }
        return d[t]>=0;
    }
    int dfs(int u,int a) {
        if(u==t||a==0) return a;
        int fl=0;
        for(int &i=cur[u];i<g[u].size();i++) {
            int ei=g[u][i];
            auto [x,v,cap,rest]=edges[ei];
            if(d[v]!=d[u]+1) continue;
            int f=dfs(v,min(a,rest));
            if(f>0) {
                edges[ei].rest-=f;
                edges[ei^1].rest+=f;
                fl+=f;
                a-=f;
                if(a==0) break;
            }
        }
        return fl;
    }
    int mxfl(int _s,int _t) {
        s=_s; t=_t;
        int an=0;
        while(bfs()) {
            cur=vector<int>(n);
            while(1) {
                int mf=dfs(s,inf);
                if(mf>0) an+=mf;
                else break;
            }
        }
        return an;
    }
};
signed main()
{
    IOS();
    Dinic F;
    int n,m;
    cin>>n>>m;
    F.init(n);
    REP(i,m) {
        int a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        F.addedge(a,b,c);
    }
    cout<<F.mxfl(0,n-1)<<"\n";
    return 0;
}
