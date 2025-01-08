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
void solve() {
    int n;
    cin>>n;
    Vi deg(n);
    vector<set<int>> g(n);
    REP(i,n-1) {
        int u,v;
        cin>>u>>v,u--,v--;
        deg[u]++,deg[v]++;
        g[u].insert(v);
        g[v].insert(u);
    }
    set<int> s;
    multiset<int> ds;
    REP(i,n) s.insert(i),ds.insert(deg[i]);
    if(*ds.rbegin()==n-1) {
        cout<<"-1\n";
        return;
    }
    Vi an;
    REP(i,n) {
        for(int u:s) {
            op(i)ope(u)oparr(ds)
            if(an.size()&&g[u].find(an.back())!=g[u].end()) continue;
            for(int v:g[u]) {
                ds.erase(ds.find(deg[v]));
                ds.insert(--deg[v]);
            }
            ds.erase(ds.find(deg[u]));
            oparr(ds)
            if(*ds.rbegin()==n-i-2&&n-i-2>0) {
                for(int v:g[u]) {
                    ds.erase(ds.find(deg[v]++));
                    ds.insert(deg[v]);
                }
                ds.insert(deg[u]);
                continue;
            }
            an.pb(u);
            s.erase(u);
            break;
        }
    }    
    for(int x:an) cout<<x+1<<' ';
    cout<<'\n';
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}