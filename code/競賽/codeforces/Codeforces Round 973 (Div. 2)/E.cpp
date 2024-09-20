#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
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
const int maxn=5;
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
void solve() {
    int n;
    cin>>n;
    Vi a(n);
    REP(i,n) cin>>a[i];
    Vi b=a;
    int gcd0=a[0];
    REP(i,n) gcd0=__gcd(gcd0,a[i]);
    int f0=gcd0;
    REP(i,n) a[i]/=gcd0;
    int gcd=0;
    Vi an(n,-1);
    REP(i,n) {
        int id=0,mn=b[0];
        REP(j,b.size()) {
            if(b[j]<mn) {
                mn=b[j];
                id=j;
            }
        }
        an[i]=b[id];
        if(b[id]==1) {
            break;
        }
        gcd=__gcd(gcd,b[id]);
        for(int j=id;j<b.size()-1;j++) b[j]=__gcd(b[j+1],gcd);
        b.pop_back();
        oparr(b)
    }
    oparr(an)
    int sum=0;
    REP(i,n) sum+=an[i];
    cout<<sum*f0<<'\n';
    entr
}
signed main() {
    IOS(); 
    int T=1;
    cin>>T;
    while(T--) 
    solve();
    return 0;
}