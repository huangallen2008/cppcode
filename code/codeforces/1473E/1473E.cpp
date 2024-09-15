#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,popcnt")
// #define int long long
#define ll long long
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
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define Graphw vector<vector<pil>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#define MD(x,M) (((x)%(M)+(M))%(M))
#define ld long double
#define pdd pair<ld,ld>
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";REP(allen,(x).size()) cout<<x[allen]<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=8e5+5;
const ll inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n,m;
int n2,n3,n4;
vector<pii> g[maxn];
void addedge(int u,int v,int w) { 
    g[u].pb({v,w});
    g[u].pb({v+n,w<<1});
    g[u].pb({v+n2,0});
    g[u].pb({v+n3,w});
    g[u+n].pb({v+n3,0});
    g[u+n].pb({v+n,w});
    g[u+n2].pb({v+n3,w<<1});
    g[u+n2].pb({v+n2,w});
    g[u+n3].pb({v+n3,w});
}
signed main() {
    IOS();
    cin>>n>>m;
    n2=n<<1,n3=n2+n,n4=n<<2;
    // Graphw g(n4);
    REP(i,m) {
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        addedge(u,v,w);
        addedge(v,u,w);
    }
    vector<ll> dis(n4,inf);
    dis[0]=0;
    priority_queue<pli,vector<pli>,greater<pli>> pq;
    pq.push({0,0});
    bitset<maxn> vis;
    while(!pq.empty()) {
        auto [d,u]=pq.top();
        pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto &[v,w]:g[u]) {
            if(dis[v]<=dis[u]+w) continue;
            dis[v]=dis[u]+w;
            pq.push({dis[v],v});
        }
    }
    for(int i=n3+1;i<n4;i++) {
        cout<<dis[i]<<' ';
    }
    cout<<'\n';
    return 0;
}