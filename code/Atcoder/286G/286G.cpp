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
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct DSU {
    vector<int> p,sz,deg,cnt;
    int n;
    void init(int _n,vector<int> &_deg) { n=_n; deg=_deg;
        p=vector<int>(n);
        cnt=vector<int>(n);
        sz=vector<int>(n,1);
        REP(i,n) {
            p[i]=i;
            cnt[i]=deg[i]&1;
        }
    }
    int find(int u) {
        if(p[u]==u) return u;
        return p[u]=find(p[u]);
    }
    void merge(int a,int b) {
        int x=find(a),y=find(b);
        if(x==y) return;
        if(sz[x]>sz[y]) swap(x,y);
        p[x]=y;
        sz[y]+=sz[x];
        cnt[y]+=cnt[x];
    }
    int cal_c() {
        int ret=0;
        REP(i,n) ret+=p[i]==i&&(cnt[i]&1);
        return ret;
    }
}dsu;
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    vector<pii> e(m);
    vector<int> deg(n);
    REP(i,m) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        e[i]={u,v};
        deg[u]++,deg[v]++;
    }
    int k;
    cin>>k;
    bitset<maxn> isu;
    dsu.init(n,deg);
    REP(i,k) {
        int x;
        cin>>x;
        x--;
        isu[x]=1;
    }
    REP(i,m) {
        if(!isu[i]) {
            auto [u,v]=e[i];
            dsu.merge(u,v);
        }
    }
    if(dsu.cal_c()<=2) cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}