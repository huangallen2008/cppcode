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
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=1e5+5;
const int maxv=4e4+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
vector<bool> vis,ins;
vector<int> p,to2,lev;
vector<pii> cyc;
Graph g;
int n,m,c;
void print(vector<int> &a) {
    cout<<a.size()<<'\n';
    for(int &v:a) cout<<v+1<<' ';
    cout<<'\n';
}
vector<int> gop(int t,int en) {
    vector<int> r={t};
    while(t!=en) {
        t=p[t];
        r.pb(t);
    }
    return r;
}
vector<int> mergev(vector<int> a,vector<int> b) {
    for(int v:b) a.pb(v);
    return a;
}
void output(int u,pii x,pii y) {//backedge:x.s->x.f
    if(lev[x.f]<lev[y.f]) swap(x,y);
    vector<int> r1=mergev({x.f},gop(x.s,u));
    vector<int> r2=mergev(gop(x.f,y.f),gop(y.s,u));
    vector<int> r3=gop(u,x.f);
    reverse(ALL(r3));
    print(r1);
    print(r2);
    print(r3);
    exit(0);
}
void dfs2(int u) {
    vis[u]=1;
    ins[u]=1;
    for(int v:g[u]) {
        if(v==p[u]) continue;
        if(ins[v]) {
            if(c==2) {
                cout<<"2\n"<<u+1<<' '<<v+1<<'\n';
                vector<int> cyc=gop(u,v);
                print(cyc);
                exit(0);
            }
            cyc[v]={v,u};
        }
        if(!vis[v]) {
            p[v]=u;
            lev[v]=lev[u]+1;
            dfs2(v);
        }
        if(cyc[v].f!=-1) {
            if(cyc[u].f==-1) cyc[u]=cyc[v];
            else output(u,cyc[u],cyc[v]);
        }
    }
    ins[u]=0;
}
signed main() {
    IOS();
    cin>>n>>m>>c;
    g=Graph(n);
    vis=vector<bool>(n);
    ins=vector<bool>(n);
    p=vector<int>(n);
    to2=vector<int>(n,-1);
    lev=vector<int>(n,-1);
    cyc=vector<pii>(n,{-1,-1});
    REP(i,m) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    REP(i,n) {
        if(!vis[i]) {
            p[i]=-1;
            dfs2(i);
        }
    }
    return 0;
}
