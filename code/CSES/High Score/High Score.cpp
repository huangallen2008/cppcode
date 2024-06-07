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
struct Edge {
    int u,v,d;
};
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    Graph g(n),gb(n);
    vector<Edge> edge0,edge;
    REP(i,m) {
        int u,v,d;
        cin>>u>>v>>d;
        u--,v--;
        g[u].pb(v);
        gb[v].pb(u);
        edge0.pb({u,v,d});
    }
    vector<bool> is(n),ie(n);
    queue<int> q;
    q.push(0);
    is[0]=1;
    vector<int> vis;
    vis=vector<int>(n);
    while(q.size()) {
        int u=q.front();
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int v:g[u]) {
            if(vis[v]) continue;
            q.push(v);
            is[v]=1;
        }
    }
    q.push(n-1);
    vis=vector<int>(n);
    ie[n-1]=1;
    while(q.size()) {
        int u=q.front();
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int v:gb[u]) {
            if(vis[v]) continue;
            q.push(v);
            ie[v]=1;
        }
    }
//    cout<<"is:";REP(i,n) cout<<is[i]<<" ";cout<<endl;
//    cout<<"ie:";REP(i,n) cout<<ie[i]<<" ";cout<<endl;
    REP(i,edge0.size()) {
        if(is[edge0[i].u]&&is[edge0[i].v]&&ie[edge0[i].u]&&ie[edge0[i].v]) edge.pb(edge0[i]);
    }
    vector<int> hs(n,-inf);
    hs[0]=0;
    bool ook=1;
    REP(rd,n) {
        bool ok=0;
        REP(i,edge.size()) {
            int u=edge[i].u,v=edge[i].v;
            int nw=hs[u]+edge[i].d;
            if(nw>hs[v]) {
                hs[v]=nw;
                ok=1;
            }
        }
        if(!ok) break;
        if(rd==n-1) ook=0;
    }
    if(ook) {
//            REP(i,n) cout<<hs[i]<<" ";cout<<endl;
        cout<<hs[n-1]<<"\n";
    }
    else cout<<"-1\n";
    return 0;
}
/*
5 6
1 2 1
2 3 2
1 4 3
4 4 1
4 5 1
3 5 1
*/
