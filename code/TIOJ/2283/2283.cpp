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
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    vector<vector<pii>> g(n+m);
    REP(i,m) {
        int k,w;
        cin>>k>>w;
        REP(j,k) {
            int x;
            cin>>x;
            x--;
            g[n+i].pb({x,w});
            g[x].pb({n+i,0});
        }
    }
    vector<int> dis(n+m,inf);
    vector<bool> vis(n+m);
    dis[0]=0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,0});
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
    int an=*max_element(dis.begin(),dis.begin()+n);
    if(an==inf) cout<<"-1\n";
    else cout<<an<<'\n';
    return 0;
}
