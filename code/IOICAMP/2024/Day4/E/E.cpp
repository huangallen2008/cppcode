#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define int long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
const int mod=1e9+7;
const int maxn=1e6+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
struct Dinic {
    struct E {
        int v,c,r,rc;
    };
    vector<vector<E>> adj;
    vector<int> vis,dis,it;
    Dinic(int n) : adj(n),vis(n),dis(n),it(n) {}
    void add(int u,int v,int c,int d=0) {
        adj[u].pb({v,c,SZ(adj[v]),c});
        adj[v].pb({u,d,SZ(adj[u])-1,d});
    }
    bool bfs(int s,int t) {
        fill(ALL(dis),inf);
        queue<int> q;
        q.push(s);
        dis[s]=0;
        while(q.size()) {
            int u=q.front();
            q.pop();
            for(auto [v,c,r,rc]:adj[u]) {
                if(dis[v]<inf||rc==0) continue;
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
        return dis[t]<inf;
    }
    int dfs(int u,int t,int cap) {
        if(u==t||cap==0) return cap;
        vis[u]=1;
        for(int &i=it[u];i<SZ(adj[u]);i++) {
            auto &[v,c,r,rc]=adj[u][i];
            if(dis[u]+1!=dis[v]) continue;
            int tmp=dfs(v,t,min(cap,rc));
            if(tmp>0) {
                rc-=tmp;
                adj[v][r].rc+=tmp;
                return tmp;
            }
        }
        return 0;
    }
    int flow(int s,int t) {
        int ans=0,tmp;
        while(bfs(s,t)) {
            fill(ALL(vis),0);
            fill(ALL(it),0);
            while((tmp=dfs(s,t,inf))>0) ans+=tmp;
        }
        return ans;
    }
    bool inscut(int u) { return dis[u]<inf; }
};
struct edge {
    int u,v,w;
};
vector<edge> gohu(int n,vector<edge> ed) {
    vector<edge> tree;
    vector<int> par(n);
    for(int i=1;i<n;i++) {
//            ope(i)
        Dinic din(n);
        for(auto &[u,v,c]:ed) {
            din.add(u,v,c,c);
        }
        tree.pb({i,par[i],din.flow(i,par[i])});
        for(int j=i+1;j<n;j++) {
            if(par[j]==par[i]&&din.inscut(j))
                par[j]=i;
        }
    }
    return tree;
}
vector<vector<pii>> g;
int n;
int bfs(int s,int t) {
    vector<int> dis(n);
    dis[s]=inf;
    queue<int> q;
    q.push(s);
    vector<bool> vis(n);
    while(q.size()) {
        int u=q.front();
        q.pop();
        vis[u]=1;
        for(auto [v,w]:g[u]) {
            if(vis[v]) continue;
            dis[v]=min(dis[u],w);
            q.push(v);
        }
    }
    return dis[t];
}
signed main() {
    IOS();
    int m,q;
    cin>>n>>m>>q;
    vector<edge> ed;
    int sum=0;
    REP(i,m) {
        int u,v,d;
        cin>>u>>v>>d;
        u--,v--;
        sum+=d;
        ed.pb({u,v,d});
    }
    vector<edge> eg=gohu(n,ed);
    g=vector<vector<pii>>(n);
    REP(i,eg.size()) {
        auto [u,v,w]=eg[i];
        g[v].pb({u,w});
        g[u].pb({v,w});
    }
//    REP(i,n) {
//        cout<<i<<":";
//        for(auto [v,w]:g[i]) cout<<"{"<<v<<','<<w<<"} ";
//        cout<<"\n";
//    }
    REP(i,q) {
        int s,t;
        cin>>s>>t;
        s--,t--;
        int an=sum-bfs(s,t);
        cout<<an<<'\n';
    }
    return 0;
}
