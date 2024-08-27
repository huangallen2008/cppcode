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
vector<int> m,a;
vector<vector<int>> g;
int dfs(int u,int mx) {
    if(SZ(g[u])==0) return max(mx,m[a[u]]+1);
    m[a[u]]++;
    mx=max(mx,m[a[u]]);
    int an=0;
    REP(i,SZ(g[u])) an=max(an,dfs(g[u][i],mx));
    m[a[u]]--;
    return an;
}
signed main()
{
    IOS();
    int n;
    cin>>n;
    g=vector<vector<int>>(n);
    a=vector<int>(n);
    m=vector<int>(n);
    REP(i,n) cin>>a[i];
    REP(i,n-1) {
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
    }
    vector<int> t=a;
    sort(ALL(t));
    REP(i,n) a[i]=lower_bound(ALL(t),a[i])-t.begin();
    cout<<dfs(0,0)<<"\n";
    return 0;
}
