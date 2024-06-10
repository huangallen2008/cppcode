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
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,char>>> g(n);
    REP(i,m) {
        int u,v;
        char c;
        cin>>u>>v>>c;
        u--,v--;
        g[u].pb({v,c});
        g[v].pb({u,c});
    }
    vector<vector<int>> dis(n,vector<int>(n,inf));
    queue<pii> q;
    q.push({0,n-1});
    dis[0][n-1]=0;
    while(q.size()) {
        auto [u1,u2]=q.front();
        q.pop();
        if(u1==u2) {
            cout<<dis[u1][u1]*2<<'\n';
            return 0;
        }
        for(auto &[v1,c1]:g[u1]) {
            if(v1==u2) {
                cout<<dis[u1][u2]*2+1<<'\n';
                return 0;
            }
            for(auto &[v2,c2]:g[u2]) {
                if(c1!=c2) continue;
                if(dis[v1][v2]<dis[u1][u2]+1) continue;
                dis[v1][v2]=dis[u1][u2]+1;
                q.push({v1,v2});
            }
        }
    }
    cout<<"-1\n"; 
    return 0;
}