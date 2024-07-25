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
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (x%mod+mod)%mod
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
const int inf=(1ll<<62);
const int maxn=1e3+5;
const int mod=1e9+7;
Graph g;
vector<int> vis,dp0,dp1;
void dfs(int u) {
    vis[u]=1;
    int mx1=-inf;
    for(int v:g[u]) {
        if(vis[v]) continue;
        dfs(v);
        dp0[u]+=dp1[v];
        mx1=max(mx1,dp0[v]-dp1[v]);
    }
    dp1[u]=dp0[u]+max(mx1+1,(int)0);
}
signed main() {
    IOS();
    int n;
    cin>>n;
    g=Graph(n);
    vis=vector<int>(n);
    dp0=vector<int>(n);
    dp1=vector<int>(n);
    REP(i,n-1) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0);
    cout<<dp1[0]<<"\n";
    return 0;
}
