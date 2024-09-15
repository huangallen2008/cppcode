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
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int inf=(1ll<<63)-1;
const int maxn=2e5+5;
const int mod=1e9+7;
vector<int> in;
vector<bool> ir;
Graph g;
vector<int> d;
vector<int> vis;
int find_ir(int u) {
    if(ir[u]) return u;
    if(vis[u]) return -1;
    vis[u]=1;
    for(int v:g[u]) {
        int r=find_ir(v);
        if(r>=0) return r;
    }
}
int dis(int u,int e,int d) {
    if(vis[u]) return -1;
    if(u==e) return d;
    vis[u]=1;
    for(int v:g[u]) {
        int r=dis(v,e,d+1);
        if(r>=0) return r;
    }
}
void solve() {
    int n,a,b;
    cin>>n>>a>>b;
    a--,b--;
    in=vector<int>(n);
    vis=vector<int>(n);
    ir=vector<bool> (n);
    g=Graph(n);
    REP(i,n) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
        in[u]++,in[v]++;
    }
    queue<int> q;
    REP(i,n) if(in[i]==1) q.push(i);
    while(q.size()) {
        int u=q.front();
        q.pop();
        ir[u]=1;
        for(int v:g[u]) {
            in[v]--;
            if(!ir[v]&&in[v]==1) q.push(v);
        }
    }
    REP(i,n) ir[i]=ir[i]^1;
//    cout<<"ir";for(auto x:ir) cout<<x<<" ";cout<<"\n";
    vis=vector<int>(n);
    while(q.size()) q.pop();
    int bi=0;
    q.push(b);
    vis[b]=1;
    while(q.size()) {
        int u=q.front();
        q.pop();
        if(ir[u]) {
            bi=u;
            break;
        }
        for(int v:g[u]) {
            if(vis[v]) continue;
            vis[v]=vis[u]+1;
            q.push(v);
        }
    }
    while(q.size()) q.pop();
    q.push(a);
    vis=vector<int>(n);
    vis[a]=1;
    while(q.size()) {
        int u=q.front();
        q.pop();
        for(int v:g[u]) {
            if(vis[v]) continue;
            vis[v]=vis[u]+1;
            q.push(v);
        }
    }
    int da=vis[bi];

//    cout<<"vis";REP(i,n) cout<<vis[i]<<" ";cout<<endl;

    while(q.size()) q.pop();
    vis=vector<int>(n);
    q.push(b);
    vis[b]=1;
    while(q.size()) {
        int u=q.front();
        q.pop();
        for(int v:g[u]) {
            if(vis[v]) continue;
            vis[v]=vis[u]+1;
            q.push(v);
        }
    }
    int db=vis[bi];

//    cout<<"bi"<<bi<<" "<<"da"<<da<<" db"<<db<<"\n";
    if(da>db) cout<<"YES\n";
    else cout<<"NO\n";
//    cout<<endl;
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}
/*
1
8 5 3
8 3
5 1
2 6
6 8
1 2
4 8
5 7
6 7

*/
