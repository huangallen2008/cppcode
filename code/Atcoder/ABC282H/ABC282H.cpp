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
#define Vpii vector<pii>
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
template<typename T1,typename T2>
ostream& operator<<(ostream& os,pair<T1,T2> p) { return os<<'{'<<p.f<<','<<p.s<<'}'; }
const int mod=1e9+7;
const int maxn=5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();
    int n,s;
    cin>>n>>s;
    Vi a(n+1),b(n+1);
    REP1(i,n) cin>>a[i];
    REP1(i,n) cin>>b[i],b[i]+=b[i-1];
    Vi l(n+1),r(n+1);
    Vpii stk;
    stk.pb({-inf,0});
    REP1(i,n) {
        while(stk.back().f>a[i]) stk.pop_back();
        l[i]=stk.back().s;
        stk.pb({a[i],i});
    }
    stk={{-inf,n+1}};
    RREP1(i,n) {
        while(stk.back().f>=a[i]) stk.pop_back();
        r[i]=stk.back().s;
        stk.pb({a[i],i});
    }
    int an=0;
    REP1(i,n) {
        if(i-l[i]<r[i]-i) {
            for(int j=l[i]+1;j<=i;j++) {
                an+=upper_bound(b.begin()+i,b.begin()+r[i],s-a[i]+b[j-1])-b.begin()-i;
            }
        }else {
            for(int j=i;j<r[i];j++) {
                an+=-(lower_bound(b.begin()+l[i],b.begin()+i,b[j]-s+a[i])-b.begin())+i;
            }
        }
    }
    cout<<an<<'\n';
    return 0;
}