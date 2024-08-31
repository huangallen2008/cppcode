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
signed main() {
    IOS();
    int n;
    cin>>n;
    vector<pii> a(n);
    REP(i,n) cin>>a[i].f>>a[i].s;
    sort(ALL(a));
    vector<pii> v(n,{inf,inf});
    vector<int> dp(n),ii(n),ll(n);
    vector<pii> la(n);
    REP(i,n) {
        int id=lower_bound(ALL(v),{a[i].s,a[i].f})-v.begin();
        v[id]={a[i].s,a[i].f};
        ll[i]=ii[id]-1;
        ii[id]=i;
        dp[i]=id;
        if(id) {
            la[i]={v[id-1].f-a[i].s,v[id-1].s-a[i].f};
        }
    }
    int mx=*max_element(ALL(dp));
    int mxi=max_element(ALL(dp))-dp.begin();
    cout<<mx<<'\n';
    string an="";
    int t=mxi;
    while(ap[t]>0) {
        REP(i,la[t].f) an+='L';
        REP(i,la[t].s) an+='D';
        t=ll[t];
    }
    reverse(ALL(an));
    cout<<an<<'\n';

    return 0;
}