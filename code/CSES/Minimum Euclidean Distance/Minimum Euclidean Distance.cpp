#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,popcnt")
// #define int long long
#define ll long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) ((x)*(ll)(x))
// #define pii pair<int,int>
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
const int maxv=1e9+5;
const ll inf=8e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
bool sort_by_y(pii a,pii b) { return a.s<b.s; }
ll dis(pii a,pii b) {
    return SQ(a.f-b.f)+SQ(a.s-b.s);
}
int recal_rng(ll x) {
    if(x>2e9) return 2e9+1;
    if(x<-2e9) return -2e9-1;
    return x;
}
ll solve(vector<pii> &p,int l,int r) {
    if(l==r) return inf;
    int m=l+r>>1;
    ll ret=min(solve(p,l,m),solve(p,m+1,r));
    ll an=ret;
    ll rng_len=recal_rng(sqrtl(ret)+1);
    ll mid=p[m].f,id=lower_bound(p.begin()+l,p.begin()+r+1,make_pair((int)recal_rng(mid-rng_len),maxv))-p.begin();
    vector<pii> t;
    for(;id<=r&&p[id].f<=mid+rng_len;id++) t.pb(p[id]);
    sort(ALL(t),sort_by_y);
    REP(i,t.size()) {
        for(int j=i+1;j<t.size();j++) {
            if(t[j].s>t[i].s+rng_len) break;
            an=min(an,dis(t[i],t[j]));
        }
    }
    return an;
}
signed main() {
    IOS();
    // freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    vector<pii> p(n);
    REP(i,n) cin>>p[i].f>>p[i].s;
    sort(ALL(p));
    ll an=solve(p,0,n-1);
    cout<<an<<'\n';
    // cout<<fixed<<setprecision(3)<<((long double)clock()/CLOCKS_PER_SEC)<<"s\n";
    return 0;
}