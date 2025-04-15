#include<bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<=(n);i++)
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define Vi vector<int>
#define Vpii vector<pii>
#define SZ(x) ((int)((x).size()))
#define ALL(x) (x).begin(),(x).end()
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define Graph vector<Vi>
#define Graphw vector<Vpii>
const int inf=(1ll<<60);
#ifdef LOCAL
#define op(x) cout<<(#x)<<'='<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) {for(auto allen:x) cout<<(allen)<<' ';cout<<endl;}
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
Graphw g;
Vi vis;
Vi ol;
Vi cur;
Vi deg;
void dfs(int u) {
    for(auto [v,id]:g[u]) {
      if(vis[id]) continue;
      ol.pb(id);
      vis[id]=1;
      deg[u]--,deg[v]--;
      dfs(v);
    }
}
std::string bicoloring(signed n,const std::vector<signed> &U,const std::vector<signed> &V) { 
    if(n==1) return "";
    int m=SZ(U);
    g=Graphw(n);
    deg=Vi(n);
    REP(i,m) {
        g[U[i]-1].pb({V[i]-1,i});
        g[V[i]-1].pb({U[i]-1,i});
    }
    Vi odd;
    int mid=m;
    ol.clear();
    vis=Vi(m+1);
    REP(i,n) if(deg[i]&1) dfs(i);
    REP(i,n) {
      while(deg[i]) dfs(i);
    }
    string an;
    REP(i,m) an+='R';
    REP(i,SZ(ol)) {
        an[ol[i]]=i&1?'R':'B';
    }
    return an;
}
