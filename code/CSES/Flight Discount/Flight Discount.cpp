#include<bits/stdc++.h>
using namespace std;
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
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int inf=(1ll<<62);
const int maxn=1e6+5;
const int mod=1e9+7;
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    vector<vector<pii>> g(n*2);
    REP(i,m) {
        int u,v,d;
        cin>>u>>v>>d;
        u--,v--;
        g[u].pb({v,d});
        g[n+u].pb({n+v,d});
        g[u].pb({n+v,d/2});
    }
    g[n-1].pb({n*2-1,0});
//    REP(i,n*2) {
//        cout<<i<<":";
//        for(auto [v,d]:g[i]) cout<<" {"<<v<<","<<d<<"} ";
//        cout<<"\n";
//    }
    vector<int> dis(n*2,-1);
    dis[0]=0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,0});
    while(pq.size()) {
        int u=pq.top().s,nd=pq.top().f;
        pq.pop();
        if(nd>dis[u]) continue;
        for(auto [v,d]:g[u]) {
            if(dis[v]==-1||dis[u]+d<dis[v]) {
                dis[v]=dis[u]+d;
//                cout<<"dis["<<v<<"]="<<dis[v]<<"\n";
                pq.push({dis[v],v});
//                cout<<"pq:push {"<<dis[v]<<","<<v<<"}\n";
            }
        }
    }
    cout<<dis[n*2-1]<<"\n";
    return 0;
}
