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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
Graphw g;
Vi vis;
Vi ol;
Vi cur;
void dfs(int u) {
    for(;cur[u]<SZ(g[u]);){
        auto [v,id]=g[u][cur[u]++];
        if(vis[id]) continue;
        vis[id]=1;
        dfs(v);
        ol.pb(id);
    }
}
std::string bicoloring(signed n,const std::vector<signed> &U,const std::vector<signed> &V) { 
    if(n==1) return "";
    int m=SZ(U);
    g=Graphw(n);
    REP(i,m) {
        g[U[i]-1].pb({V[i]-1,i});
        g[V[i]-1].pb({U[i]-1,i});
    }
    string an;
    int nowmn=inf;
    REP(i,1<<m) {
        #ifdef LOCAL
        if(i!=25) continue;
        #endif
        Vi cnt0(n),cnt1(n);
        bool ok=1;
        REP(u,n) {
            for(auto [v,id]:g[u]) {
                if(i>>id&1) cnt1[u]++;
                else cnt0[u]++;
            }
            op(cnt0[u])ope(cnt1[u])
            if(abs(cnt0[u]-cnt1[u])>1) {
                ok=0;
                break;
            }
        }
        if(!ok) break;
        int tv=0;
        int c0=0,c1=0;
        REP(j,m) {
            if(i>>j&1) c1++;
            else c0++;
        }
        int dif=abs(c0-c1);
        string r;
        REP(j,m) {
            if(i>>j&1) r+='R';
            else r+='B';
        }
        ope(dif)
        if(dif<nowmn) {
            nowmn=dif;
            an=r;
        }
    }
    return an;
}
