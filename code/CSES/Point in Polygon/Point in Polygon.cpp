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
#define LOCAL
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
const int maxv=2e9+5;
const int inf=(1ll<<60);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int cros(pii a,pii b) { return a.f*b.s-a.s*b.f; }
int dot(pii a,pii b) { return a.f*b.f+a.s*b.s; }
pii to(pii a,pii b) { return {b.f-a.f,b.s-a.s}; }
int sign(int x) { if(x<0) return -1;else if(x>0) return 1;else return 0; }
bool inters(pii l1,pii l2,pii p1,pii p2) {
    pii ln=to(l1,l2);// line l1_l 
    if(sign(cros(ln,to(l1,p1)))*sign(cros(ln,to(l1,p2)))>0) return 0;
    ln=to(p1,p2);//line p1_p2
    if(sign(cros(ln,to(p1,l1)))*sign(cros(ln,to(p1,l2)))>0) return 0;
    return 1;
}
bool onl(pii l1,pii l2,pii p) {
    if(cros(to(l1,l2),to(l1,p))!=0) return 0;
    if(dot(to(l1,l2),to(l1,p))>=0&&dot(to(l2,l1),to(l2,p))>=0) return 1;
    return 0;
}
void in_polygon(int n,pii p0,vector<pii> &p) {
    pii l1=p0,l2={p0.f+1,p0.s+maxv};
    REP(i,n) {
        if(onl(p[i],p[i+1],p0)) {
            cout<<"BOUNDARY\n";
            return ;
        }
    }
    int cnt=0;
    REP(i,n) {
        cnt+=inters(l1,l2,p[i],p[i+1]);
    }
    if(cnt&1) cout<<"INSIDE\n";
    else cout<<"OUTSIDE\n";
}
signed main() {
    IOS();
    int n,q;
    cin>>n>>q;
    vector<pii> p(n+1);
    REP(i,n) cin>>p[i].f>>p[i].s;
    p[n]=p[0];
    REP(rd,q) {
        pii p0;
        cin>>p0.f>>p0.s;
        in_polygon(n,p0,p);
    }
    return 0;
}
