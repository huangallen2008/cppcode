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
const int maxb=20;
const int inf=(1ll<<62); 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int pw(int x,int p) {
    int r=1;
    while(p>0) {
        if(p&1) r=r*x%mod;
        x=x*x%mod;
        p>>=1;
    }
    return r;
}
int inv(int x) { 
    return pw(x,mod-2);
}
const int inv2=inv(2);
Vi fac(maxn),infac(maxn);
int C(int n,int k) {
    return (fac[n]*infac[k]%mod)*infac[n-k]%mod;
}
int H(int n,int k) {
    return C(n+k-1,k);
}
signed main() {
    IOS();
    fac[0]=1;
    REP1(i,maxn-1) fac[i]=fac[i-1]*i%mod;
    infac[maxn-1]=inv(fac[maxn-1]);
    RREP(i,maxn-1) infac[i]=infac[i+1]*(i+1)%mod;
    int n;
    cin>>n;
    Vi a(n);
    REP(i,n) cin>>a[i];
    unordered_map<int,int> mp;
    int an=1;
    ope(an)
    REP(i,n) {
        mp[a[i]]++;
        if(mp[a[i]]>=2) {
            an=(an*mp[a[i]]*(mp[a[i]]-1)%mod)*inv2%mod;
        }
        op(i)ope(an)
    }
    int cnt=0;
    Vi t=a;
    sort(ALL(t));
    // t.resize(unique(ALL(t))-t.begin());
    for(auto [x,y]:mp) {
        if(y>=2) {
            an=(an*H((lower_bound(ALL(t),x)-t.begin())+1,y-1))%mod;
        }
    }
    ope(an)
    op(cnt)
    // an=an*infac[n-cnt]%mod;
    cout<<an<<'\n';
    return 0;
}