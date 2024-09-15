#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
<<<<<<< HEAD
#pragma GCC target("avx2,sse4,bmi2,popcnt")
=======
// #pragma GCC target("avx2,sse4,bmi,popcnt")
>>>>>>> 78541cbc0a0b07e855f7a8b89d63696cc483800d
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
const int mod=998244353;
const int maxn=1e8+5;
const ll inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
#ifdef LOCAL
#define GC _getchar_nolock()
#define PC _putchar_nolock
#else 
#define GC getchar_unlocked()
#define PC putchar_unlocked
#endif
inline ll read()
{
    ll x=0;
    char c=GC;
    while(c<'0'||c>'9'){c=GC;}
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=GC;
    return x;
}
signed main() {
    IOS();
    int n=read();
    ll k=read();
    // cin>>n>>k;
    vector<ll> a(n+1);
    REP1(i,n) a[i]=read();
    vector<pair<ll,int>> stk;
    vector<pair<int,ll>>b;
    stk.pb({inf,0});
    REP1(i,n) {
        // for(auto [x,y]:stk) cout<<"{"<<x<<","<<y<<"} ";entr
        while(a[i]>=stk.back().f) {
            if(stk.size()>2) b.pb({i-stk[stk.size()-2].s-1,a[i]>=stk[stk.size()-2].f?stk[stk.size()-2].f-stk.back().f:a[i]-stk.back().f});
            stk.pop_back();
        }
        stk.pb({a[i],i});
    }
    ll an=0;
    REP1(i,n-1) an+=abs(a[i]-a[i+1]);
    // for(auto &[x,y]:b) cout<<x<<' '<<y<<'\n';
    sort(ALL(b));
    REP(i,b.size()) {
        if(k>=b[i].f*b[i].s) {
            an-=b[i].s<<1;
            k-=b[i].f*b[i].s;
        }
        else {
            an-=(k/b[i].f)<<1;
            break;
        }
    }
    cout<<an<<'\n';
    return 0;
}