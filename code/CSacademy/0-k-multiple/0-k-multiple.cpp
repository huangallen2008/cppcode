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
const int mod=998244353;
const int maxn=1e7+5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS(); 
    int n,k;
    cin>>n>>k;
    if(k==n) {
        cout<<n<<'\n';
        return 0;
    }
    Vi dis(n,inf);
    vector<pii> las(n,{-1,-1});
    dis[k]=0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,k});
    vector<bool> vis(n);
    while(pq.size()) {
        int u=pq.top().s;
        pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        auto _=[&](int v,int w,int t){
            //v=,w=,t
            if(dis[v]>dis[u]+w) {
                dis[v]=dis[u]+w;
                las[v]={u,t};
                pq.push({dis[v],v});
            }
        };
        _(u*10%n,1,0);
        _((u*10+k)%n,1,k);
    }
    oparr(dis)
    int tu=0;
    string an;
    while(tu!=k) {
        an+='0'+las[tu].s;
        tu=las[tu].f;
    }
    an+='0'+k;
    reverse(ALL(an));
    cout<<an<<'\n';
    return 0;
}