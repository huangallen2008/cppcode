#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,fast-math")
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
#define oparr(x) cout<<(#x)<<":";for(auto &mken:(x)) cout<<mken<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=2e6;
const int inf=(1<<30);
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
#define int16 int16_t
struct SEG {
    int s[maxn];
    int lc[maxn];
    int rc[maxn];
    int16 n;
    int node_id=1;
    Vi ver;
    int _ud(int w,int l,int r,int u,int v) {
        int nn=node_id++;
        if(!w) w=nn;
        lc[nn]=lc[w],rc[nn]=rc[w],s[nn]=s[w];
        if(l==r) {
            s[nn]+=v;
            return nn;
        }
        int m=l+r>>1;
        if(u<=m) lc[nn]=_ud(lc[nn],l,m,u,v);
        else rc[nn]=_ud(rc[nn],m+1,r,u,v);
        s[nn]=s[lc[nn]]+s[rc[nn]];
        return nn;
    }
    int ud(int root,int u,int v) {
        return _ud(root,0,n-1,u,v);
    }
    void init(int16 _n,Vi &a) {
        n=_n+1;
        ver=Vi(_n+1);
        ver[0]=1;
        Vi las(n);
        REP1(i,_n) {
            ver[i]=ud(ud(ver[i-1],las[a[i]],-1),i,1);
            las[a[i]]=i;
        }
    }
    int _qu(int &w,int l,int r,int &ql,int &qr) {
        if(!w) return 0;
        if(ql<=l&&r<=qr) return s[w];
        if(ql>r||qr<l) return 0;
        int m=l+r>>1;
        return _qu(lc[w],l,m,ql,qr)+_qu(rc[w],m+1,r,ql,qr);
    }
    int qu(int l,int r) {
        return _qu(ver[r],0,n-1,l,r);
    }
}seg;
vector<int16> dp,ndp;
int n,k;
void _solve(int l,int r,int mn,int mx) {
    if(l>r) return;
    if(mn==mx) {
        for(int i=l;i<=r;i++) ndp[i]=dp[mn]+seg.qu(mn+1,i);
        return;
    }
    int m=l+r>>1;
    int id=0,lim=min(mx,m-1);
    for(int i=mn;i<=lim;i++) {
        int nv=dp[i]+seg.qu(i+1,m);
        if(nv>ndp[m]) {
            ndp[m]=nv;
            id=i;
        }
    }
    _solve(l,m-1,mn,id);
    _solve(m+1,r,id,mx);
}
void solve() {
    _solve(1,n,0,n-1);
    dp.swap(ndp);
    ndp=vector<int16>(n+1);
}
signed main() {
    IOS(); 
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif
    // cin>>n>>k;
    n=read(),k=read();
    Vi a(n+1);
    REP1(i,n) a[i]=read();
    Vi t(n);
    REP1(i,n) t[i-1]=a[i];
    sort(ALL(t));
    REP1(i,n) a[i]=lower_bound(ALL(t),a[i])-t.begin();
    ope(n)
    seg.init(n,a);
    dp=ndp=vector<int16>(n+1);
    REP(i,k) solve();
    cout<<dp[n]<<'\n';
    #ifdef LOCAL
        cout<<fixed<<setprecision(3)<<(ld)clock()/CLOCKS_PER_SEC<<'\n';
    #endif
    return 0;
}