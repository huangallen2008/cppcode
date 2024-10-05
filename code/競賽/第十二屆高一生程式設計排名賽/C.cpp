#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,bmi,popcnt")
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
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";REP(allen,(x).size()) cout<<x[allen]<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int qu(auto &mp,auto x) {
    if(mp.find(x)==mp.end()) return 0;
    return mp[x];
}
signed main() {
    IOS();
    int n;
    cin>>n;
    map<int,int> mp_a,mp_b,mp_c;
    map<pii,int> mp_ab,mp_ac,mp_bc;
    map<pipii,int> mp_abc;
    int an=0;
    REP(i,n) {
        int a,b,c;
        cin>>a>>b>>c;
        pii vab={a,b},vac={a,c},vbc={b,c};
        pipii vabc={a,{b,c}};
        an+=qu(mp_a,a)+qu(mp_b,b)+qu(mp_c,c)-qu(mp_ab,vab)-qu(mp_bc,vbc)-qu(mp_ac,vac)+qu(mp_abc,vabc);
        mp_a[a]++;
        mp_b[b]++;
        mp_c[c]++;
        mp_ab[vab]++;
        mp_ac[vac]++;
        mp_bc[vbc]++;
        mp_abc[vabc]++;
    } 
    cout<<an<<'\n';
    return 0;
}
