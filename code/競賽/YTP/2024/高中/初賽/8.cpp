#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
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
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";REP(i,(x).size()) cout<<x[i]<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=5e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
struct DSU {
    vector<int> p,sz,ti;
    int n,sum=0;
    void init(int _n) {
        n=_n;
        p=vector<int>(n);
        sz=vector<int>(n,1);
        ti=vector<int>(n);
        REP(i,n) p[i]=i;
        sum=0;
    }
    int find(int u) {
        if(p[u]==u) return u;
        return find(p[u]);
    }
    void merge(int a,int b,int v) {
        int x=find(a),y=find(b);
        if(x==y) return;
        sum+=v;
        if(sz[x]>sz[y]) swap(x,y);
        p[x]=y;
        sz[y]+=sz[x];
        ti[x]=v;
    }
    int max_val(int a,int b) {
        int an=0;
        if(find(a)!=find(b)) return inf;
        while(a!=b) {
            if(sz[a]>sz[b]) swap(a,b);
            an=max(an,ti[a]);
            a=p[a];
        }
        return an;
    }
} dsu;
struct Edge {
    int u,v,d,id;
};
bool so(Edge a,Edge b) {
    return a.d<b.d;
}
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    dsu.init(n);
    vector<Edge> edges;
    REP(i,m) {
        int u,v,d;
        cin>>u>>v>>d;
        u--,v--;
        edges.pb({u,v,d,i});
    }
    sort(ALL(edges),so);
    for(auto [u,v,d,id]:edges) dsu.merge(u,v,d);
    vector<int> an(m);
    for(auto [u,v,d,id]:edges) {
        an[id]=dsu.sum+d-dsu.max_val(u,v);
    }
    REP(i,m) cout<<an[i]<<'\n';
    return 0;
}