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
    vector<vector<pii>> g(n);
    REP(i,m) {
        int u,v,l;
        cin>>u>>v>>l;
        u--,v--;
        g[u].pb({v,l});
    }
    vector<int> an(n,inf);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,0});
    an[0]=0;
    vector<int> vis(n);
    while(pq.size()) {
        int u=pq.top().s,d=pq.top().f;
        pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto [v,l]:g[u]) {
            if(an[v]<=an[u]+l) continue;
            an[v]=an[u]+l;
            pq.push({an[v],v});
        }
    }
    REP(i,n) cout<<an[i]<<" ";
    cout<<"\n";
    return 0;
}
