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
vector<vector<pii>> g;
vector<int> vis,c0,c1,an;
void dfs(int u) {
    if(vis[u]) return;
    vis[u]=1;
    vector<int> c(2);
    for(auto [v,t]:g[u]) {
        if(vis[v]) continue;
        dfs(v);
        c0[u]+=c0[v];
        c1[u]+=c1[v];
        if(t==0) c0[u]++;
        else c1[u]++;
    }
}
int p=0;
void cnt(int u) {
//    cout<<u<<"\n";
    if(vis[u]) return;
    vis[u]=1;
//    bool ok=0;
    for(auto [v,t]:g[u]) {
        if(vis[v]) continue;
        an[v]=c1[u]+(-t*2+1)+p;
        p+=c1[u]-c1[v]-t-t+1;
        cnt(v);
        p-=c1[u]-c1[v]-t-t+1;
//        ok=1;
    }
}
signed main() {
    IOS();
    int n,k;
    cin>>n>>k;
    vis=vector<int>(n);
    c0=vector<int>(n);
    c1=vector<int>(n);
    an=vector<int>(n);
    g=vector<vector<pii>>(n);
    REP(i,n-1) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb({v,0});
        g[v].pb({u,1});
    }
    dfs(0);
//    cout<<"c0:";REP(i,n) cout<<c0[i]<<" ";cout<<"\n";
//    cout<<"c1:";REP(i,n) cout<<c1[i]<<" ";cout<<"\n";
    an[0]=c1[0];
    vis=vector<int>(n);
    cnt(0);
    REP(i,k) {
        int x;
        cin>>x;
        x--;
        cout<<an[x]<<" ";
    }
    cout<<"\n";
    return 0;
}
