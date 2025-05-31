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
#define ppi pair<pii,int>
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
const int maxn=1e6+5;
const int maxv=5000+5;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct SCC {
    vector<int> sccid,dfn,val,dis;
    bitset<maxn> vis;
    int sccc=0;
    Graph ng,ngb;
    Graph g,gb;
    int an=0;
    bool init(int n,Graph &_g,Vi vs) {
        g=_g;
        sccid=vector<int>(n);
        dfn.clear();
        sccc=0;
        an=0;
        vis.reset();
        REP(i,n) if(!vis[i]) dfs1(i);
        reverse(ALL(dfn));
        gb=Graph(n);
        REP(u,n) for(auto v:g[u]) gb[v].pb(u);
        vis.reset();
        REP(i,n) {
            int u=dfn[i];
            if(!vis[u]) {
                sccid[u]=sccc++;
                dfs2(u);
            }
        }
        ngb=Graph(n);
        REP(u,n) {
            for(auto v:g[u]) {
                if(sccid[u]!=sccid[v]) {
                    ngb[sccid[v]].pb(sccid[u]);
                }
            }
        }
        vis.reset();
        val=Vi(sccc,-inf);
        REP(i,SZ(vs)) {
            if(val[sccid[i]]==-inf) val[sccid[i]]=vs[i];
            else if(val[sccid[i]]!=vs[i]) return 0;
        }
        REP(i,sccc) {
            if(val[i]==-inf) {
                for(int v:ngb[i]) {
                    chmax(val[i],val[v]);
                }
            }else {
                for(int v:ngb[i]) {
                    if(val[v]>val[i]) return 0;
                }
            }
        }
        return 1;
        // dis=val;
        // REP(u,sccc) {
        //     for(auto v:ngb[u]) {
        //         chmax(dis[u],dis[v]+val[u]);
        //     }
        // }
        // an=*max_element(ALL(dis));
    }
    void dfs1(int u) {
        vis[u]=1;
        for(auto v:g[u]) {
            if(vis[v]) continue;
            dfs1(v);
        }
        dfn.pb(u);
    }
    void dfs2(int u) {
        vis[u]=1;
        for(auto v:gb[u]) {
            if(vis[v]) continue;
            sccid[v]=sccid[u];
            dfs2(v);
        }
    }
}scc;
void solve() {
    int n,q;
    cin>>n>>q;
    Vi a(n);
    REP(i,n) cin>>a[i];
    Vi vs=a;
    sort(ALL(vs));
    vs.erase(unique(ALL(vs)),vs.end());
    int N=q+vs.size();
    int node_id=vs.size();
    // oparr(vs)
    Vi id(n);
    REP(i,n) id[i]=lower_bound(ALL(vs),a[i])-vs.begin();
    struct S {
        int x,y,z;
    };
    vector<S> qu(q);
    REP(i,q) cin>>qu[i].x>>qu[i].y>>qu[i].z,qu[i].x--,qu[i].y--,qu[i].z--;
    reverse(ALL(qu));
    Graph g(N);
    auto add=[&](int u,int v) {
        // op(u)ope(v)
        g[u].pb(v);
    };
    for(auto [x,y,z]:qu) {
        // op(x)op(y)ope(z)
        if(z!=x&&z!=y) {
            add(id[z],id[x]);
            add(id[z],id[y]);
            int _=id[z];
            id[z]=node_id++;
            add(_,id[z]);
        }else {
            if(z==y) swap(x,y);
            //now z==x is true
            add(id[z],id[y]);
            int _=id[z];
            id[z]=node_id++;
            add(_,id[z]);
        }
    }
    // ope("ok")
    int ret=scc.init(N,g,vs);
    // oparr(id)
    if(ret==0) cout<<"-1\n";
    else {
        Vi an(n);
        REP(i,n) an[i]=scc.val[scc.sccid[id[i]]];
        REP(i,n) cout<<an[i]<<' ';
        cout<<'\n';
    }
    // entr
    // ope(ret)
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
/*
3
2 1
1 2
2 1 2
3 2
1 2 3
2 3 2
1 2 1
6 4
1 2 2 3 4 5
5 6 6
4 5 5
3 4 4
2 3 3

*/