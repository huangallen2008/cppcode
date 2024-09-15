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
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
const int inf=(1ll<<62);
const int maxn=1e5+5;
const int mod=1e9+7;
Graph g;
vector<int> an,v;
bool so(int a,int b) { return a>b; }
int vid=0;
void dfs(int u,int la) {
    an[u]=v[vid++];
    for(int v:g[u]) {
        if(v==la) continue;
        dfs(v,u);
    }
}
signed main() {
    IOS();
    int n;
    cin>>n;
    g=Graph(n);
    REP(i,n-1) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    an=vector<int> (n);
    v=vector<int> (n);
    REP(i,n) cin>>v[i];
    sort(ALL(v),so);
    int sum=0,mx=v[0];
    REP(i,n) sum+=v[i];
    dfs(0,-1);
    cout<<sum-mx<<'\n';
    REP(i,n) cout<<an[i]<<' ';
    cout<<'\n';
    return 0;
}
