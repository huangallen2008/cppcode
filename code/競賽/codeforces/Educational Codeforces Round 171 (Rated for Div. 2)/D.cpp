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
const int maxn=1e5+5;
const int maxb=30;
const int inf=(1ll<<62); 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
void solve() {
    int n;
    cin>>n;
    Vi a(n+1);
    REP1(i,n) cin>>a[i];
    REP1(i,n) a[i]+=a[i-1];
    Vi p(n+1),s(n+2),ss(n+2),sm(n+2);
    REP1(i,n) p[i]=p[i-1]+a[i];
    RREP1(i,n) s[i]=s[i+1]+a[i];
    RREP1(i,n) ss[i]=ss[i+1]+s[i];
    RREP(i,n) sm[i]=sm[i+1]+(a[i]*(n-i));
    int q;
    cin>>q;
    auto id=[&](int x) {
        int l=1,r=n,m;
        while(l<r) {//last m : m*(m+1)>>1 <x
            m=l+r+1>>1;
            if((m*(m+1)>>1)<x) l=m;
            else r=m-1;
        }
        int i1=l,i2=x-(l*(l+1)>>1);
        return {i1,i2};
    };
    auto cost_s=[&](int x) {
        return ss[n-x+1]-sm[n-x];
    };
    auto cost_p=[&](pii x) {
        return s[n-x.s+1]-a[n-x.f]*x.s;
    };
    auto cost=[&](pii x) {
        return cost_s(x.f)+cost_p(x);

    };
    int all=n*(n+1)>>1;
    REP(i,q) {
        int l,r;
        cin>>l>>r;
        l=all-l+1;
        r=all-r+1;
        int an=cost(l)-cost(r+1);
        cout<<an<<'\n';
    }
}
signed main() {
    IOS(); 
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}