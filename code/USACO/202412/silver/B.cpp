#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi2,popcnt")
// #define int long long
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
#define oparr(x) cout<<(#x)<<":";for(auto allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
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
const int maxn=1e5;
const int maxb=20;
const int inf=(1<<30);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct edge {
    int u,v,w;
};
bitset<maxn> vis;
void solve() {
    vis.reset();
    int n,k;
    cin>>n>>k;
    Vi a(n+1);
    a[0]=-inf;
    REP1(i,n) cin>>a[i];
    Vi t=a;
    sort(ALL(t));
    int N=n+2;
    Vi cnt(N);
    REP(i,n+1) {
        a[i]=(lower_bound(ALL(t),a[i])-t.begin())+1;
        cnt[a[i]]++;
    }
    Graphw g(N);
    vector<edge> e;
    for(int i=2;i<N;i++) {
        g[i-1].pb({i,cnt[i]});
        g[i].pb({i-1,0});
    }
    REP1(i,N-1) g[0].pb({i,0});
    REP(i,k) {
        int l,r,x;
        cin>>l>>r>>x;
        l=lower_bound(ALL(t),l)-t.begin(),l++;
        r=upper_bound(ALL(t),r)-t.begin();
        g[r].pb({l-1,-x});
    }
    Vi dis(N,inf);
    dis[0]=0;
    queue<int> q;
    q.push(0);
    vis[0]=1;
    while(q.size()) {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(auto [v,w]:g[u]) {
            if(dis[v]>dis[u]+w) {
                dis[v]=dis[u]+w;
                if(!vis[v]) q.push(v),vis[v]=1;
            }
        }
    }
    int rest=dis[n+1]-dis[1];
    // ope(rest)
    cout<<n-rest<<'\n';
    // entr
    // ope("ok")
}
signed main() {
    IOS();
    // freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    while(T--) {
        solve();
        // ope("ok")
    }
    return 0;
}