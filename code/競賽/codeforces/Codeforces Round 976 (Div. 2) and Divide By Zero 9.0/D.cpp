#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
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
#define Vi vector<int>
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
const int mod=998244353;
const int modm=mod-1;
const int maxn=5;
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct DSU {
    Vi p,sz;
    int n;
    int cc;
    void init(int _n) {
        n=_n;
        p=Vi(n);
        sz=Vi(n,1);
        REP(i,n) p[i]=i;
        cc=n;
    }
    int find(int u) {
        return p[u]==u?u:p[u]=find(p[u]);
    }
    void merge(int a,int b) {
        // op(a)ope(b)
        int x=find(a),y=find(b);
        if(x==y) return;
        if(sz[x]>sz[y]) swap(x,y);
        p[x]=y;
        sz[y]+=sz[x];
        cc--;
    }
}dsu;
void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<Vi>> p(11,vector<Vi>(11,Vi(n)));
    REP(i,m) {
        int a,d,k;
        cin>>a>>d>>k,a--;
        int id=a%d,l=a/d;
        p[d][id][l]++;
        p[d][id][l+k]--;
    }
    dsu.init(n);
    REP1(d,10) {
        REP(id,d) {
            int pr=0;
            REP(i,n/d+1) {
                pr+=p[d][id][i];
                if(pr>0) dsu.merge(i*d+id,(i+1)*d+id);
            }
        }
    }
    cout<<dsu.cc<<'\n';
}
signed main() {
    IOS(); 
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}