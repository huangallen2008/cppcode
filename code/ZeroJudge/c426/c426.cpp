#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
const int inf=(1ll<<62)-1;
const int maxn=5e3+5;
const int mod=1e9+7;
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    vector<int> a;
    vector<vector<int>> mn,mx;
    int T;
    cin>>T;
    while(T--) {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> g(n);
        vector<int> d(n),c(n),o(n);
        int an1=0,an2=0;
        REP(i,m) {
            int u,v;
            cin>>u>>v;
            g[u].pb(v);
            g[v].pb(u);
            d[u]++;
            d[v]++;
            an1=max(an1,++c[min(u,v)]);
        }
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        REP(i,n) pq.push({d[i],i});
        while(pq.size()) {
            int v=pq.top().f,u=pq.top().s;
            pq.pop();
            if(o[u]) continue;
            o[u]=1;
            an2=max(an2,d[u]);
            REP(i,g[u].size()) if(!o[g[u][i]]) pq.push({--d[g[u][i]],g[u][i]});
        }
        cout<<an1<<" "<<an2<<"\n";
    }
    return 0;
}
