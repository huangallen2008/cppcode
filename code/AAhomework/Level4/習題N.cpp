#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define int long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
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
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";REP(idd,(x).size()) cout<<x[idd]<<" ";cout<<endl;
#define entr cout<<endl;
const int inf=(1ll<<62);
const int maxn=6e5+5;
const int mod=1e9+7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    vector<vector<pii>> g(n);
    REP(i,m) {
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    vector<int> dis0(n,inf),dis1(n,inf),dis(n,inf);
    vector<bool> vis(n);
    pq.push({0,0}); dis0[0]=0;
    while(pq.size()) {
        int u=pq.top().s;
        pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto [v,d]:g[u]) {
            if(dis0[v]<=dis0[u]+d) continue;
            dis0[v]=dis0[u]+d;
            pq.push({dis0[v],v});
        }
    }
    vis=vector<bool>(n);
    pq.push({0,1}); dis1[1]=0;
    while(pq.size()) {
        int u=pq.top().s;
        pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto [v,d]:g[u]) {
            if(dis1[v]<=dis1[u]+d) continue;
            dis1[v]=dis1[u]+d;
            pq.push({dis1[v],v});
        }
    }
    vis=vector<bool>(n);
    REP(i,n) {
        dis[i]=dis0[i]+dis1[i];
        pq.push({dis[i],i});
    }
    while(pq.size()) {
        int u=pq.top().s;
        pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto [v,d]:g[u]) {
            if(dis[v]<=dis[u]+d) continue;
            dis[v]=dis[u]+d;
            pq.push({dis[v],v});
        }
    }
    for(int i=2;i<n;i++) cout<<dis[i]<<'\n';
    return 0;
}
