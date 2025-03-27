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
#define SZ(x) ((int)((x).size()))
#define SQ(x) ((x)*(x))
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
template<typename T1,typename T2>
pair<T1,T2> operator+(pair<T1,T2> p1,pair<T1,T2> p2) { return pair<T1,T2>(p1.f+p2.f,p1.s+p2.s); }
const int mod=998244353;
const int maxn=2e5+5;
const int maxv=2e9+5;
const int inf=8e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();
    int n;
    cin>>n;
    pii mx={0,-1};
    int N=n*(n-1)>>1;
    REP(mask,1ll<<(N)) {
        // if(mask!=504) continue;
        if(~mask&1) continue;
        if(__builtin_popcountll(mask)<=mx.f) continue;
        int it=0;
        Graph g(n);
        REP(i,n) {
            REP(j,i) {
                // op(i)op(j)op(it)ope(mask>>it&1)
                if(mask>>(it++)&1) {
                    g[i].pb(j);
                    g[j].pb(i);
                }
            }
        }
        // op(mask)ope(g)
        bool ok=1;
        int val=__builtin_popcountll(mask);
        REP(u,n) {
            for(int v:g[u]) {
                if(__gcd(SZ(g[u]),SZ(g[v]))!=1) {
                    // op(u)ope(v)
                    ok=0;
                    break;
                }
            }
            if(!ok) break;
        }
        if(!ok) continue;
        // op(val)ope(mask)
        pii rr={val,mask};
        chmax(mx,rr);
    }
    // REP(mask,1<<(N)) {
    //     // if(mask!=504) continue;
    //     int it=0;
    //     Graph g(n);
    //     REP(i,n) {
    //         REP(j,i) {
    //             // op(i)op(j)op(it)ope(mask>>it&1)
    //             if(mask>>(it++)&1) {
    //                 g[i].pb(j);
    //                 g[j].pb(i);
    //             }
    //         }
    //     }
    //     // op(mask)ope(g)
    //     bool ok=1;
    //     int val=__builtin_popcount(mask);
    //     REP(u,n) {
    //         for(int v:g[u]) {
    //             if(__gcd(SZ(g[u]),SZ(g[v]))!=1) {
    //                 // op(u)ope(v)
    //                 ok=0;
    //                 break;
    //             }
    //         }
    //         if(!ok) break;
    //     }
    //     if(!ok) continue;
    //     // op(val)ope(mask)
    //     pii rr={val,mask};
    //     if(val==mx.f) {
    //         oparr(g)
    //     }
    // }
    ope(mx)
    return 0;
}