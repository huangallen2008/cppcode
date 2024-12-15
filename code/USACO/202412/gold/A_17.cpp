#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
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
const int maxn=1e5;
const int maxb=20;
const int inf=(1<<30);
const int B=500;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();
    int n;
    cin>>n;
    vector<Vi> b(n);
    Vi a(n);
    int mxa=0;
    REP(i,n) cin>>a[i],a[i]--,b[a[i]].pb(i),mxa=max(mxa,a[i]);
    int nn=-1;
    if(n<=5000) nn=n;
    if(mxa<10) nn=mxa+1;
    auto cal=[&](int i,int x) {
        if(b[i].size()==0) return 0;
        int id=0,an=0;
        while(id<b[i].size()) {
            id=upper_bound(ALL(b[i]),b[i][id]+x)-b[i].begin();
            an++;
        }
        return an;
    };
    auto fnd=[&](int i,int k) {//last t : when x=t,->cal(i,x)>=k
        int lb=0,rb=n,mb;
        while(lb<rb) {
            mb=lb+rb+1>>1;
            if(cal(i,mb)>=k) lb=mb;
            else rb=mb-1;
        }
        return lb;
    };
    Vi an1(n+1),an2(n+1);
    REP(i,n) {
        int sz=b[i].size();
        if(sz<=B) {
            REP1(j,b[i].size()) an2[fnd(i,j)]++;
            continue;
        }
        // int cnt=0;
        REP1(x,n) {
            int id=0;
            while(id<b[i].size()) {
                id=upper_bound(ALL(b[i]),b[i][id]+x)-b[i].begin();
                an1[x]++;
            }
        }
        // an+=cnt;
    }
    RREP(i,n) an2[i]+=an2[i+1];
    REP1(i,n) {
        cout<<an1[i]+an2[i]<<'\n';
    }
    return 0;
}