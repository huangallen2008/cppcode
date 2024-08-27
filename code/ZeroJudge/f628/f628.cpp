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
signed main()
{
    IOS();
    int n,m;
    cin>>n>>m;
    vector<vector<pii>> g(n);
    REP(i,m) {
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        g[u].pb({v,w});
    }
    vector<int> a(n,-1);
    a[0]=0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    REP(i,SZ(g[0])) pq.push({g[0][i].s,g[0][i].f});
    while(pq.size()) {
        pii p=pq.top();
        pq.pop();
        if(a[p.s]!=-1) continue;
        a[p.s]=p.f;
        REP(i,SZ(g[p.s])) pq.push({p.f+g[p.s][i].s,g[p.s][i].f});
    }
    int an=0;
    REP(i,n) an+=a[i];
    cout<<an<<"\n";
    return 0;
}
