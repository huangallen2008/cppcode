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
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct line {
    int x0,y0,dx,dy;
    line(int x,int y,int mx,int my) {
        x0=x,y0=y;
        dx=mx,dx=my;
        if(dx<0) dx=-dx,dy=-dy;
        int g=__gcd(abs(dx),abs(dy));
        dx/=g,dy/=g;
    }
};
bool inl(line l,pii p) {
    if(l.dx==0) return p.f==l.x0;
    if(l.dy==0) return p.s==l.y0;
    return (p.s-l.y0)*l.dx==(p.f-l.x0)*l.dy;
}
signed main() {
    IOS();
    int n;
    cin>>n;
    if(n<=4) {
        cout<<"YES\n";
        return 0;
    }
    vector<pii> p(n);
    REP(i,n) cin>>p[i].f>>p[i].s;
    while((ld)clock()/CLOCKS_PER_SEC<0.9) {
        int p1=rd(0,n-1),p2=rd(0,n-1);
        if(p1==p2) continue;
        line l1(p[p1].f,p[p1].s,p[p2].f-p[p1].f,p[p2].s-p[p1].s);
        vector<pii> r;
        for(auto t:p) if(!inl(l1,t)) r.pb(t);
    }
    return 0;
}