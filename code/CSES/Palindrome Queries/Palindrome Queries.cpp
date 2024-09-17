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
const int mod=1e9+21;
const int maxn=5;
const int maxc=29;
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int toi(char c) { return c-'a'+1; }
struct BIT {
    Vi b;
    int n;
    void init(int _n) {
        n=_n;
        b=Vi(n+1);
        s=string(n+1);
    }
    void _ud(int u,int v) {
        for(;u<=n;u+=u&-u) b[u]+=v;
    }
    void ud(int u,char c) {

    }
    int qu(int u,int )
}
signed main() {
    IOS(); 
    int n,m;
    cin>>n>>m;
    string str;
    cin>>str;
    str="$"+str;
    Vi p(n+1),s(n+2),po(n+1);
    po[0]=1;
    REP1(i,n) po[i]=po[i-1]*maxc%mod;
    REP1(i,n) p[i]=(p[i-1]+toi(str[i])*po[i])%mod;
    RREP1(i,n) s[i]=(s[i+1]+toi(str[i])*po[i])%mod;

    return 0;
}