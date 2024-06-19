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
const int maxn=20+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct edge {
    int u,v,w;
};
struct DSU {
    vector<int> p,sz;
    int cnt;
    void init(int n) {
        p=vector<int>(n);
        sz=vector<int>(n,1);
        REP(i,n) p[i]=i;
    }
    int find(int u) {
        if(p[u]==u) return u;
        return p[u]=find(p[u]);
    }
    void merge(int a,int b) {
        int x=find(a),y=find(b);
        if(x==y) return ;
        if(sz[x]>sz[y]) swap(x,y);
        p[x]=y;
        sz[y]+=sz[x];
    }
    void merge(edge p) {
        merge(p.u,p.v);
    }
    bool sameg(int a,int b) {
        return find(a)==find(b);
    }
    bool sameg(edge p) {
        return find(p.u)==find(p.v);
    }
};
struct C {
    DSU dsu;
    int sum;
    int id;
};
struct so_C {
    bool operator()(C &a,C &b) {
        return a.sum>b.sum;
    }
};
bool so(edge a,edge b) {
    return a.w<b.w;
}
signed main() {
    IOS();
    int n,m,k;
    cin>>n>>m>>k;
    vector<edge> edges;
    REP(i,m) {
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        edges.pb({u,v,w});
    }
    sort(ALL(edges),so);
    priority_queue<C,vector<C>,so_C> pq;
    DSU dsu0;dsu0.init(n);
    pq.push({dsu0,edges[0].w,0});
    while(k--) {
        auto [dsu,sum,id]=pq.top();
        pq.pop();
        int nid=id+1;
        while(id<edges.size()-1&&dsu.sameg(edges[nid])) nid++;
        if(id<edges.size()-1)pq.push({dsu,sum-edges[id].w+edges[nid].w,id+1});
        dsu.merge(edges[id]);
        pq.push({dsu,sum+edges[id+1].w,id+1});
    }
    int an=pq.top().sum;
    cout<<an<<'\n';
    return 0;
}
