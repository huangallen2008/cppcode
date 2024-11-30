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
const int maxn=5;
const int maxv=31700;
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
#define ull unsigned long long
signed main() {
    IOS();
    int n,b;
    cin>>n>>b;
    Vi a(n);
    REP(i,n) cin>>a[i];
    int sum=0;
    REP(i,n) sum+=a[i];
    int cnt=0;
    int n1=n>>1,n2=n-n1;
    Vi s1(1<<n1),s2(1<<n2);
    for(int i=1;i<1<<n1;i++) s1[i]=s1[i^(i&-i)]+a[__lg(i&-i)];
    for(int i=1;i<1<<n2;i++) s2[i]=s2[i^(i&-i)]+a[n1+__lg(i&-i)];
    vector<pii> v1(1<<n1),v2(1<<n2);
    REP(i,1<<n1) v1[i]={s1[i],1<<n1-__builtin_popcount(i)};
    REP(i,1<<n2) v2[i]={s2[i],1<<n2-__builtin_popcount(i)};
    sort(ALL(v1));
    sort(ALL(v2));
    int lim=sum+b+1>>1;
    int it=(1<<n2)-1;
    ull anb=0;
    int a2=0;
    REP(i,1<<n1) {
        while(it>=0&&v2[it].f+v1[i].f>=lim) {
            a2+=v2[it].s;
            it--;
        }
        anb+=v1[i].s*a2;
    }
    ull an=1;
    REP(i,n) an*=3;
    an-=anb*3;
    cout<<an<<'\n';
    return 0;
}
