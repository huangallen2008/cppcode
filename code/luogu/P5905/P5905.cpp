#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,sse4.1,sse4.2,bmi2,popcnt")
// #define int long long
#define ll long long
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
const int maxn=3e3+5;
const int maxb=18;
const int inf=1e9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
#define GC getchar()
#define PC putchar
inline int in(){
    int x=0;
    bool neg=0;
    char c=GC;
    while(c<'0'||c>'9'){if(c=='-') neg=1;c=GC;}
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=GC;
    if(neg) x=(~x)+1;
    return x;
}
inline void out(ll x) {
    if(x<0) {
        PC('-');
        x=~(x-1);
    }
    char str[18];
	auto it=str;
    do { 
        *it=x%10+'0',it++;
        x/=10;
    } while(x);
    for(it--;it>=str;it--) PC(*it);
    PC('\n');
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
inline void bellm(const int st) {
    dis0=vector<int>(n+1,inf);
    dis0[st]=0;
    int ts=n+1;
    shuffle(ALL(e),rng);
    while(ts--) {
        bool ok=0;
        for(const auto &[u,v,w]:e) {
            if(dis0[u]+w<dis0[v]) {
                dis0[v]=dis0[u]+w;
                ok=1;
            }
        }
        if(!ok) break;
        if(!ts) {
            ncyc=1;
        }
    }
}
inline void dijk(const int st) {
    priority_queue<pii> pq;
    dis=vector<int>(n+1,inf);
    dis[st]=0;
    pq.push({0,st});
    bitset<maxn> vis;
    while(pq.size()) {
        auto [dd,u]=pq.top();
        pq.pop();
        vis[u]=1;
        for(auto &[v,w]:g[u]) {
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
    n=in(),m=in();
    // cin>>n>>m;
    g=Graphw(n+1);
    e.reserve(n+m);
    REP(i,m) {
        int u,v,w;
        u=in(),v=in(),w=in();
        // cin>>u>>v>>w;
        g[u].pb({v,w});
        e.pb({u,v,w});
    }
    g[0].reserve(n);
    REP1(i,n) {
        g[0].pb({i,0});
        e.pb({0,i,0});
    }
    bellm(0);
    if(ncyc){
        out(-1);
        // cout<<"-1\n";
        return 0;
    }
    REP(u,n+1) {
        for(auto &[v,w]:g[u]) {
            w+=dis0[u]-dis0[v];
        }
    }
    REP1(i,n) {
        dijk(i);
        ll an=0;
        REP1(j,n) {
            if(dis[j]==inf) an+=1e9*(ll)j;
            else {
                int dj=dis[j]+dis0[j]-dis0[i];
                an+=(ll)dj*j;
            }
        }
        out(an);
        // cout<<an<<'\n';
    }
    return 0;
}