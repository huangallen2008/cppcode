#include<bits/stdc++.h>
using namespace std;
<<<<<<< HEAD
// #pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
#define int long long
=======
#pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
// #define int long long
#define ll long long
>>>>>>> 0b1a1b11a3c05bbc53306c9c4fc912c08c4ad5ba
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
const int mod=1e9+7;
const int maxn=100+5;
const int maxk=10;
<<<<<<< HEAD
const int inf=(1ll<<50);
=======
const int inf=(1ll<<62);
>>>>>>> 0b1a1b11a3c05bbc53306c9c4fc912c08c4ad5ba
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int dp[1<<maxk][maxn+1];
Graphw g;
int n,m,k;
vector<int> a,b,dis;
void dijk() {
    dis=vector<int>(n+1,inf);
    vector<bool> vis(n+1);
    priority_queue<pii> pq;
    pq.push({0,0});
    dis[0]=0;
    while(pq.size()) {
        auto [d,u]=pq.top();
        pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto &[v,w]:g[u]) {
            if(dis[v]<=dis[u]+w) continue;
            dis[v]=dis[u]+w;
            pq.push({-dis[v],v});
        }
    }
}
signed main() {
    IOS();
    cin>>n>>m>>k;
<<<<<<< HEAD
    REP1(i,(1<<k)-1) REP(j,n+1) dp[i][j]=inf;
=======
>>>>>>> 0b1a1b11a3c05bbc53306c9c4fc912c08c4ad5ba
    g=Graphw(n+1);
    a=vector<int>(k+1);
    b=vector<int>(n+1,-1);
    dis=vector<int>(n+1);
    REP(i,m) {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    REP(i,k) cin>>a[i],b[a[i]]=i;
    REP1(i,(1<<k)-1) {
        g[0].clear();
        REP1(j,n) {
            int mk=i;
            if(b[j]!=-1&&((mk>>b[j])&1)) mk^=(1<<b[j]);
<<<<<<< HEAD
            int t=dp[mk][j]+dp[0][j];
            for(int l=mk;l>0;l=(l-1)&mk) {
                chmin(t,dp[l][j]+dp[mk^l][j]);
            }
=======
            int t=inf;
            for(int l=mk;l>0;l=(l-1)&mk) chmin(t,dp[l][j]+dp[mk^l][j]);
>>>>>>> 0b1a1b11a3c05bbc53306c9c4fc912c08c4ad5ba
            g[0].pb({j,t});
        }
        dijk();
        REP(j,n+1) dp[i][j]=dis[j];
    }
<<<<<<< HEAD
    int an=*min_element(dp[(1<<k)-1]+1,dp[(1<<k)-1]+n);
=======
    int an=*max_element(dp[(1<<k)-1],dp[(1<<k)-1]+n);
>>>>>>> 0b1a1b11a3c05bbc53306c9c4fc912c08c4ad5ba
    cout<<an<<'\n';
    return 0;
}