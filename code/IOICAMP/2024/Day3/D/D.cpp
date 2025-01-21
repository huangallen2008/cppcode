#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define int long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
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
const int mod=1e9+7;
const int maxn=1e6+5;
const int inf=(1ll<<62);
vector<vector<pii>> g;
int n,m;
vector<pii> edge;
vector<int> cur,in,out;
vector<bool> vis;
vector<int> an,an2;
void dfs(int u) {
    for(;cur[u]<g[u].size();cur[u]++) {
        int i=cur[u];
        int v=g[u][i].f;
        int id=g[u][i].s;
        if(vis[id]) continue;
        vis[id]=1;
        dfs(v);
        an.pb(id);
    }
}
void dfs2(int u) {
    for(;cur[u]>=0;cur[u]--) {
        int i=cur[u];
        int v=g[u][i].f;
        int id=g[u][i].s;
        if(vis[id]) continue;
        vis[id]=1;
        dfs2(v);
        an2.pb(id);
    }
}
signed main() {
    IOS();
    cin>>n>>m;
    cur=vector<int>(n);
    in=vector<int>(n);
    out=vector<int>(n);
    vis=vector<bool>(m);
    g=vector<vector<pii>>(n);
    REP(i,m) {
        int u,v;
        cin>>u>>v;
        edge.pb({u,v});
        u--,v--;
        g[u].pb({v,i});
        in[v]++;
        out[u]++;
    }
    dfs(0);
    if(an.size()<m||edge[an.back()].s!=n-1) {
        cout<<"0\n";
        return 0;
    }
    REP(i,n) cur[i]=g[i].size()-1;
    vis=vector<bool>(m);
    dfs2(0);
    bool sa=1;
    REP(i,n) {
        if(an[i]!=an2[i]) {
            sa=0;
            break;
        }
    }
    if(sa) cout<<"1\n";
    else cout<<"2\n";
    RREP(i,m) {
        cout<<edge[an[i]].f<<' '<<edge[an[i]].s<<'\n';
    }
    return 0;
}
