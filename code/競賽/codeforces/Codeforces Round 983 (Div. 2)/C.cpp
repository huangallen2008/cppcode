#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("Ofast,unroll-loops,fast-math")
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
#define ALL1(x) (x).begin()+1,(x).end()
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
const int maxn2=2e5+5;
const int maxb=19;
const int inf=(1ll<<62); 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n;
int check(int m,Vi &a) {//oh fuck Q m d
    int an=0;
    REP(i,n) if(a[i]<m) an+=m-a[i];
    int mx=m*2-1;
    REP(i,n) if(a[i]>mx) an+=a[i]-mx;
    return an;
}
void solve() {
    cin>>n;
    Vi a(n);
    REP(i,n) cin>>a[i];
    sort(ALL(a));
    int an=0;
    REP(i,n-1) {
        int mx=a[i]+a[i+1]-1;
        int r=i;
        int id=(upper_bound(ALL(a),mx)-a.begin())-1;
        r+=n-id;
        chmax(an,r);
    }
    // if(a[0]+a[1]>a.back()) {
    //     cout<<"0\n";
    //     return;
    // }
    // if(a[1]*2>a.back()) {
    //     int an=a.back()-a[1]+1-a[0];
    //     cout<<an<<'\n';
    //     return;
    // }
    // int lb=a[0],rb=a.back(),mb;
    // while(lb<rb) {
    //     mb=lb+rb>>1;
    //     int r1=check(mb,a),r2=check(mb+1,a);
    //     if(r2-r1>=0) rb=mb;
    //     else lb=mb+1;
    // }
    // int an=check(lb,a);
    cout<<an<<'\n';
}
signed main() {
    IOS(); 
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}