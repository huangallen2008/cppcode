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
vector<bool> o;
vector<int> s;
Graph g;
vector<bool> vis;
int cnt=0;
int mn=inf;
void d(int u) {
    if(vis[u]) return;
    vis[u]=1;
    cnt++;
    mn=min(mn,s[u]);
    for(int v:g[u]) if(o[v]) d(v);
}
signed main()
{
    IOS();
    int n,m;
    cin>>n>>m;
    g=Graph(n);
    s=vector<int>(n);
    o=vector<bool>(n,0);
    REP(i,m) {
        int x,y;
        cin>>x>>y;
        x--,y--;
        g[x].pb(y);
        g[y].pb(x);
        s[x]++;
        s[y]++;
    }
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    REP(i,n) pq.push({s[i],i});
    vector<int> t;
    while(pq.size()) {
        int u=pq.top().s;
        pq.pop();
        if(o[u]) continue;
        o[u]=1;
        t.pb(u);
        for(int v:g[u]) {
            if(o[v]) continue;
            pq.push({--s[v],v});
        }
    }
    REP(i,n/2) swap(t[i],t[n-i-1]);
    s=vector<int>(n);
    o=vector<bool>(n,0);
    int an=0;
    REP(i,n) {
        vis=vector<bool>(n);
        cnt=0;
        mn=inf;
        int u=t[i];
        o[u]=1;
        for(int v:g[u]) {
            if(!o[v]) continue;
            s[u]++;
            s[v]++;
        }
        d(u);
        an=max(an,cnt*mn);
    }
    cout<<an<<"\n";
    return 0;
}
