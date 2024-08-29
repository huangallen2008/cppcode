#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,popcnt")
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
const int mod=1e9+7;
const int maxn=255;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
pii to(pii a,pii b) { return {b.f-a.f,b.s-a.s}; }
int cros(pii a,pii b) { return a.f*b.s-a.s*b.f; }
int sign(int x) { if(x>0) return 1;if(x<0) return -1; return 0; }
bool kill1(pii a,pii b,pii c) {//1:can kill
    return cros(to(a,b),to(a,c))<0;
}
bool kill2(pii a,pii b,pii c) {//1:can kill
    return cros(to(a,b),to(a,c))>0;
}
signed main() {
    IOS();
    int n;
    cin>>n;
    vector<pii> p(n);
    REP(i,n) cin>>p[i].f>>p[i].s;
    sort(ALL(p));
    vector<pii> convex={p[0]};
    REP1(i,n-1) {
        while(convex.size()>=2&&kill1(convex[SZ(convex)-2],convex[SZ(convex)-1],p[i])) convex.pop_back();
        convex.pb(p[i]);
    }
    RREP(i,n-1) {
        while(convex.size()>=2&&kill1(convex[SZ(convex)-2],convex[SZ(convex)-1],p[i])) convex.pop_back();
        convex.pb(p[i]);
    }
    convex.pop_back();
    cout<<convex.size()<<'\n';
    sort(ALL(convex));
    for(auto &[x,y]:convex) cout<<x<<' '<<y<<'\n';
    return 0;
}