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
        int u,v,d;
        cin>>u>>v>>d;
        u--,v--;
        g[u].pb({v,d});
    }
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,0});
    vector<int> dis(n,inf),cnt(n,0),mn(n,inf),mx(n,-inf);
    dis[0]=0,cnt[0]=1,mn[0]=0,mx[0]=0;
    while(pq.size()) {
        auto [l,u]=pq.top();
        pq.pop();
        if(l>dis[u]) continue;
        for(auto [v,d]:g[u]) {
            int nd=dis[u]+d;
            if(dis[v]<nd) continue;
            if(dis[v]==nd) {
                cnt[v]=(cnt[v]+cnt[u])%mod;
                mn[v]=min(mn[v],mn[u]+1);
                mx[v]=max(mx[v],mx[u]+1);
            }
            else {
                dis[v]=nd;
                cnt[v]=cnt[u];
                mn[v]=mn[u]+1;
                mx[v]=mx[u]+1;
                pq.push({nd,v});
            }
        }
    }
    cout<<dis[n-1]<<" "<<cnt[n-1]<<" "<<mn[n-1]<<" "<<mx[n-1]<<"\n";
    return 0;
}
