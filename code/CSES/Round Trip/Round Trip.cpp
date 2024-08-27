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
int n,m;
Graph g;
vector<int> p,an,vis;
bool ok=0;
void dfs(int u) {
//    cout<<u<<endl;
    vis[u]=1;
    for(int v:g[u]) {
        if(ok) return;
        if(vis[v]) {
            if(p[u]==v) continue;
            int th=v,nw=u;
            an.pb(th);
            while(nw!=th) {
                an.pb(nw);
                nw=p[nw];
            }
            an.pb(th);
            ok=1;
            return;
        }
        p[v]=u;
        dfs(v);
    }
}
signed main() {
    IOS();
    cin>>n>>m;
    g=Graph(n);
    p=vector<int>(n,-1);
    REP(i,m) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    vis=vector<int>(n);
    REP(i,n) {
        if(vis[i]) continue;
        dfs(i);
    }
    if(an.size()==0) {
        cout<<"IMPOSSIBLE\n";
    }
    else {
        cout<<an.size()<<"\n";
        RREP(i,an.size()) cout<<an[i]+1<<" ";
        cout<<"\n";
    }
    return 0;
}
