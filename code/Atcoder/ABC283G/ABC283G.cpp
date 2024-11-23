#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi2,popcnt")
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
#define oparr(x) cout<<(#x)<<":";for(auto allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=6e6+5;
const int maxb=60;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
Vi bas(maxb);
int cntb=0;
bool ins(int x) {
    RREP(i,maxb) if(x>>i&1) {
        if(!bas[i]) {
            bas[i]=x;
            return 1;
        }
        x^=bas[i];
    }
    return 0;
}
int kth(int k) {
    k--;
    int nb=cntb-1;
    int now=0;
    RREP(i,maxb) if(bas[i]) {
        if((now>>i&1)!=(k>>nb&1)) now^=bas[i];
        nb--;
    }
    return now;
}
signed main() {
    IOS();
    int n,l,r;
    cin>>n>>l>>r;
    Vi a(n);
    REP(i,n) {
        cin>>a[i];
        cntb+=ins(a[i]);
    }
    for(int i=l;i<=r;i++) cout<<kth(i)<<' ';
    cout<<'\n';
    return 0;
}