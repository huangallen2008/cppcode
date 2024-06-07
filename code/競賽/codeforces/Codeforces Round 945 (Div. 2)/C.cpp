#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,popcnt")
#define int long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#define MD(x,M) (((x)%(M)+(M))%(M))
#define ld long double
#define pdd pair<ld,ld>
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
const int mod=998244353;
const int maxn=3e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    REP(i,n) cin>>a[i];
    vector<pii> ev,od;
    REP(i,n) {
        if(i&1) od.pb({n+1-a[i],i});
        else ev.pb({n+1-a[i],i});
    }
    sort(ALL(od));
    sort(ALL(ev));
    vector<int> an(n);
    if(od[0].f==1) {
        an[ev[0].s]=1;
        for(int i=1;i<ev.size();i++) an[ev[i].s]=ev[i-1].f;
        an[od[0].s]=ev.back().f;
        for(int i=1;i<od.size();i++) an[od[i].s]=od[i].f;
    }
    else {
        an[od[0].s]=1;
        for(int i=1;i<od.size();i++) an[od[i].s]=od[i-1].f;
        an[ev[0].s]=od.back().f;
        for(int i=1;i<ev.size();i++) an[ev[i].s]=ev[i].f;
    }
    REP(i,n) cout<<an[i]<<' ';cout<<'\n';
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}