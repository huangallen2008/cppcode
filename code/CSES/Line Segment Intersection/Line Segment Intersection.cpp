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
const int maxv=1e3+5;
const int inf=(1ll<<60);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
pii to(pii a,pii b) { return {b.f-a.f,b.s-a.s}; }
int cros(pii a,pii b) { return a.f*b.s-a.s*b.f; }
int dot(pii a,pii b) { return a.f*b.f+a.s*b.s; }
int sign(int x) { if(x>0) return 1;else if(x<0) return -1;else return 0; }
bool onl(pii l1,pii l2,pii p) {
    return cros(to(l1,l2),to(l1,p))==0&&dot(to(l1,l2),to(l1,p))>=0&&dot(to(l2,l1),to(l2,p))>=0;
}
bool dif_side(pii a,pii b,pii c,pii d) {
    return sign(cros(to(a,b),to(a,c)))*sign(cros(to(a,b),to(a,d)))<0;
}
bool inters(pii a,pii b,pii c,pii d) {
    return dif_side(a,b,c,d)&&dif_side(c,d,a,b);
}
void solve() {
    pii p1,p2,p3,p4;
    cin>>p1.f>>p1.s;
    cin>>p2.f>>p2.s;
    cin>>p3.f>>p3.s;
    cin>>p4.f>>p4.s;
    if(onl(p1,p2,p3)||onl(p1,p2,p4)||onl(p3,p4,p1)||onl(p3,p4,p2)) cout<<"YES\n";
    else if(inters(p1,p2,p3,p4)) {
        cout<<"YES\n";
    }
    else cout<<"NO\n";
}
signed main() {
    IOS();
    //huehuvinwreiouvhnworeigvnwer
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
