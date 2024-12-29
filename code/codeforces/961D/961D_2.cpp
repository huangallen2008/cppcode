#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,sse4,bmi2,popcnt")
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
#define Vi vector<int>
#define Vpii vector<pii>
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) {cout<<(#x)<<":";for(auto allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;}
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
template<typename T1,typename T2>
ostream& operator<<(ostream& os,pair<T1,T2> p) { return os<<'{'<<p.f<<','<<p.s<<'}'; }
template<typename T1,typename T2>
istream& operator>>(istream& os,pair<T1,T2> &p) { return os>>p.f>>p.s; }
template<typename S>
ostream& operator<<(ostream& os,vector<S> p) { for(auto allen:p) os<<allen<<' ';return os<<'\n'; }
template<typename S>
istream& operator>>(istream& os,vector<S> &p) { for(auto &allen:p) os>>allen;return os; }
const int mod=998244353;
const int maxn=5;
const int maxb=64;
const int inf=1e9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct po{
    int x,y;
    po(){}
    po(pii p) { x=p.f,y=p.s; }
    po(int f,int s) { x=f,y=s; }
    po operator-(po b) {
        return {x-b.x,y-b.y};
    }
};
istream& operator>>(istream& os,po &p) { return os>>p.x>>p.y; }
ostream& operator<<(ostream& os,po p) { return os<<"{"<<p.x<<","<<p.y<<"}"; }
po to(po a,po b) { return b-a; }
int sig(int x) { if(x<0) return -1;if(x>0) return 1; return 0; }
int dot(po a,po b) { return a.x*b.x+a.y*b.y; }
int cro(po a,po b) { return a.x*b.y-a.y*b.x; }
signed main() {
    IOS();
    int n;
    cin>>n;
    vector<po> a(n);
    cin>>a;
    if(n<=2) {
        cout<<"Yes\n";
        return 0;
    }
    auto check=[&](po u,po v) {
        vector<po> r;
        REP(i,n) {
            if(cro(v-u,a[i]-u)) r.pb(a[i]);
        }
        if(r.size()<=2) return 1;
        po u2=r[0],v2=r[1];
        for(auto x:r) if(cro(v2-u2,x-u2)) return 0;
        return 1;
    };
    if(check(a[0],a[1])||check(a[0],a[2])||check(a[1],a[2])) cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}