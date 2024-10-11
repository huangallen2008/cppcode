#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
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
const int maxn=5;
const int maxb=20;
const ll inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
// #ifdef LOCAL
#define GC _getchar_nolock()
#define PC _putchar_nolock
// #else 
// #define GC getchar_unlocked()
// #define PC putchar_unlocked
// #endif
inline int read()
{
    int x=0;
    bool neg=0;
    char c=GC;
    while(c<'0'||c>'9'){if(c=='-') neg=1;c=GC;}
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=GC;
    if(neg) x=-x;
    return x;
}
inline ll readl()
{
    ll x=0;
    bool neg=0;
    char c=GC;
    while(c<'0'||c>'9'){if(c=='-') neg=1;c=GC;}
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=GC;
    if(neg) x=-x;
    return x;
}
inline void out(int x) {
    if(x<0) {
        PC('-');
        x=-x;
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
#define pli pair<ll,int>
void solve() {
    int n=read(),m=read();
    // cin>>n>>m;
    Vi c(n);
    REP(i,n) c[i]=read(); 
    // cin>>c[i];
    sort(ALL(c));
    int k=c.back();
    vector<ll> dis(k,inf);
    // priority_queue<pli,vector<pli>,greater<pli>> pq;
    deque<ll> dq;
    dis[0]=0;
    // pq.push
    dq.pb(0);
    vector<bool> vis(k);
    while(dq.size()) {
        int u=dq.front();
        pq.pop_front();
        if(vis[u]) continue;
        vis[u]=1;
        REP(i,n-1) {
            int v=u+c[i];
            if(v>=k) {
                v-=k;
                if(dis[v]>dis[u]+1) {
                    dis[v]=dis[u]+1;
                    dq.pb(dis[v]);
                }
            }
            else {
                if(dis[v]>dis[u]) {
                    dis[v]=dis[u];
                    dq.push_front(v);
                }
            }
        }
    }
    REP(i,m) {
        ll p=readl();
        // cin>>p;
        if(p>=dis[p%k]) PC('Y');//cout<<"Y";
        else PC('N');//cout<<"N";
    }
    PC('\n');
    // cout<<'\n';
}
signed main() {
    IOS(); 
    int T=read();
    // cin>>T;
    while(T--) solve();
    return 0;
}