#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
#define int long long
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<=(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) (int)((x).size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define Graphw vector<vector<pii>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#define MD(x,M) (((x)%(M)+(M))%(M))
#define ld long double
#define pdd pair<ld,ld>
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define addmod(x,y) x=((x+(y))%mod)
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";for(auto &mken:(x)) cout<<mken<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=19260817;
const int maxn=5e5+5;
const int maxb=18;
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct edge {
    int u,v,w;
};
int n,m;
Graphw g;
vector<edge> e;
vector<int> dis0;
vector<int> dis;
bool ncyc=0;
void bellm(int st) {
    dis0=vector<int>(n,inf);
    dis0[st]=0;
    REP(rd,n) {
        bool ok=0;
        for(auto [u,v,w]:e) {
            if(dis0[u]+w<dis0[v]) {
                dis0[v]=dis0[u]+w;
                ok=1;
            }
        }
        if(!ok) break;
        if(rd==n-1) {
            ncyc=1;
        }
    }
}
void dijk(int st) {
    priority_queue<pii> pq;
    dis=vector<int>(n,inf);
    dis[st]=0;
    pq.push({0,st});
    vector<bool> vis(n);
    while(pq.size()) {
        auto [dd,u]=pq.top();
        pq.pop();
        vis[u]=1;
        for(auto [v,w]:g[u]) {
            if(vis[v]) continue;
            if(dis[u]+w<dis[v]) {
                dis[v]=dis[u]+w;
                pq.push({-dis[v],v});
            }
        }
    }
}
signed main() {
    IOS();
    cin>>n>>m;
    g=Graphw(n);
    REP(i,m) {
        int u,v,w;
        cin>>u>>v>>w,u--,v--;
        g[u].pb({v,w});
        e.pb({u,v,w});
    }
    bellm(0);
    if(ncyc){
        cout<<"-1\n";
        return 0;
    }
    REP(u,n) {
        for(auto &[v,w]:g[u]) {
            w+=dis0[u]-dis0[v];
        }
    }
    REP(i,n) {
        dijk(i);
        int an=0;
        REP(j,n) {
            if(dis[j]==inf) an+=1e9*(j+1);
            else {
                int dj=dis[j]+dis0[j]-dis0[i];
                an+=dj*(j+1);
            }
        }
        cout<<an<<'\n';
    }
    return 0;
}