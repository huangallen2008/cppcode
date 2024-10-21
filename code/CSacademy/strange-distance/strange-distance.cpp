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
const int maxn=1e5+1;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct BIT {
    int n;
    Vi b;
    void init(int _n) {
        n=_n;
        b=Vi(n+1);
    }
    void ud(int u,int v) {
        for(;u<=n;u+=u&-u) b[u]+=v;
    }
    int pre(int u) {
        int r=0;
        for(;u>0;u-=u&-u) r+=b[u];
        return r;
    }
    int sum(int l,int r) {
        return pre(r)-pre(l-1);
    }
    int qur(int x,int d) {
        int l1=0,r1=max(x-d,0ll);
        int l2=min(x+d,n),r2=n;
        return sum(l1,r1)+sum(l2,r2);
    }
}bit;
signed main() {
    IOS(); 
    int n,k;
    cin>>n>>k;
    k=(n*(n-1)>>1)-k+1;
    vector<pii> a(n);
    REP(i,n) cin>>a[i].f>>a[i].s;
    sort(ALL(a));
    int lb=0,rb=maxn,mb;
    while(lb<rb) {
        mb=lb+rb+1>>1;//last t : r(>=mb) >=k
        bit.init(maxn);
        int r=0;
        int l=0;
        REP(i,n) {
            while(l<n&&a[l].f+mb<=a[i].f) {
                bit.ud(a[l++].s,1);
            }
            op(i)ope(l)
            r+=bit.qur(a[i].s,mb);
        }
        l=n-1;entr
        RREP(i,n) {
            while(l>=0&&a[l].f-mb<=a[i].f) {
                bit.ud(a[l--].s,1);
            }
            op(i)ope(l)
            r+=bit.qur(a[i].s,mb);
        }
        op(mb)ope(r)entr
        if(r>=k) lb=mb;
        else rb=mb-1;
    }
    cout<<lb<<'\n';
    return 0;
}