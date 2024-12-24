#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi2,popcnt")
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
#define Vi vector<int>
#define Vpii vector<pii>
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) {cout<<(#x)<<":";for(auto allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;}
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
template<typename T1,typename T2>
ostream& operator<<(ostream& os,pair<T1,T2> p) { return os<<'{'<<p.f<<','<<p.s<<'}'; }
const int mod=1e9+7;
const int maxn=5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//                                                                   11  12                           17    18   19  20            
const Vpii e={{1,2},{1,3},{1,4},{1,5},{1,6},{2,3},{3,4},{4,5},{5,6},{6,2},{2,9},{2,8},{3,8},{3,7},{4,7},{4,11},{5,11},{5,10},{6,10},{6,9},{7,8},{8,9},{9,10},{10,11},{11,7},{7,12},{8,12},{9,12},{10,12},{11,12}};
signed main() {
    IOS();
    int s,t;
    cin>>s>>t,s--,t--;
    Graphw g(12);
    for(auto [u,v]:e) {
        int w;
        cin>>w;
        u--,v--;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    Vi dis(12,inf);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,s});
    dis[s]=0;
    Vi vis(12);
    while(pq.size()) {
        auto [u,mocha]=pq.top();
        pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto [v,w]:g[u]) {
            if(dis[v]>dis[u]+1) {
                dis[v]=dis[u]+w;
                pq.push({dis[v],v});
            }
        }
    }
    oparr(dis)
    cout<<dis[t]<<'\n';
    return 0;
}