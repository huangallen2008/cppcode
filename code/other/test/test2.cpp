#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,bmi,popcnt")
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
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";for(auto &allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=2e5+5;
const ll inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n,k,x,y,z;
ll cost(int v) {
    if(v<0) return (ll)x*(-v);
    else return (ll)y*v;
}
signed main(){
    IOS();
    cin>>n>>k>>x>>y>>z;
    vector<int> a(n);
    REP(i,n) cin>>a[i];
    vector<int> s(1<<n);
    for(int i=1;i<1<<n;i++) {
        s[i]=s[i^(i&-i)]+a[__lg(i&-i)];
    }
    vector<pii> f;
    for(int i=1;i*i<=k;i++) if(k%i==0) f.pb({i,k/i});
    ll an=inf;
    REP(i,1<<n) {
        if(i==0||(i&-i)==i) continue;
        int cnt1=__builtin_popcount(i),v=(cnt1-2)*z;
        for(int j=(i-1)&i;j>0;j=(j-1)&i) {
            if(__builtin_popcount(j)>(cnt1>>1)) continue;
            for(auto &[f1,f2]:f) {
                chmin(an,min(cost(s[j]-f1)+cost(s[j^i]-f2),cost(s[j]-f2)+cost(s[j^i]-f1))+v);
            }
        }
    }
    cout<<an<<'\n';
    return 0;
}
