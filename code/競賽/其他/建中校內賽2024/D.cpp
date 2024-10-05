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
#define Vi vector<int>
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
const int maxn=505;
const int maxv=31700;
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();
    int n,m,l;
    cin>>n>>m>>l;
    Vi a(l);
    REP(i,n) cin>>a[i];
    Graphw g(n);
    REP(i,m) {
        int u,v,w;
        cin>>u>>v>>w,u--,v--;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    priority_queue<pair<int,pipii>,vector<pair<int,pipii>>,greater<pair<int,pipii>>> pq;
    pq.push({0,{0,{-1,-1}}});
    Vi dis(n,inf),pre(n),prew(n);
    dis[0]=0;
    vector<bool> vis(n);
    while(pq.size()) {
        int u=pq.top().s.f,l=pq.top().s.s.f,lw=pq.top().s.s.s;
        ope(u)
        pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        pre[u]=l;
        prew[u]=lw;
        for(auto [v,w]:g[u]) {
            int ww=dis[u]+w;
            if(dis[v]>dis[u]+w) {
                dis[v]=dis[u]+w;
                pq.push({v,{dis[v],{u,w}}});
            }
        }
    }
    ope("oeo")
    Vi r;
    int t=n,tw=0;;
    while(t!=0) {
        tw=pre[t];
        r.pb(tw);
        t=pre[t];
    }
    for(int x:r) cout<<x<<' ';entr
    int ll=1,rr=1e18,mi;
    while(ll<rr) {
        mi=ll+rr>>1;
        Vi nr;
        for(int x:r) nr.pb(mi/x);
        int it=0;
        bool ok=1;
        for(int x:nr) {
            if(it==l) ok=0;
            while(it<l&&a[it]>=x) it++;
            it++;
        }
        if(ok) rr=mi;
        else ll=mi+1;
    }
    cout<<ll<<'\n';
    return 0;
}