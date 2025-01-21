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
#define Graphw vector<vector<pii>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
const int mod=1e9+7;
const int maxn=1e6+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
Graphw g,gb;
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    g=Graphw(n);
    gb=Graphw(n);
    vector<int> ind(n);
    REP(i,m) {
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        g[u].pb({v,w});
        gb[v].pb({u,w});
        ind[v]++;
    }
    queue<int> q;
    vector<int> tpsort;
    REP(i,n) if(ind[i]==0) q.push(i);
    while(q.size()) {
        int u=q.front();
        q.pop();
        tpsort.pb(u);
        for(auto [v,w]:g[u]) {
            ind[v]--;
            if(ind[v]==0) q.push(v);
        }
    }
    vector<int> ldis(n,0);
    REP(i,n) {
        int u=tpsort[i];
        for(auto [v,w]:gb[u]) {
            ldis[u]=max(ldis[u],ldis[v]+w);
        }
    }
    cout<<"-1\n";
    REP1(del,n-2) {
        ldis=vector<int>(n,-inf);
        ldis[0]=0;
        REP(i,n) {
            int u=tpsort[i];
            if(u==del) continue;
            for(auto [v,w]:gb[u]) {
                if(v==del) continue;
                ldis[u]=max(ldis[u],ldis[v]+w);
            }
        }
//        oparr(ldis)
        vector<int> cntr(n);
        cntr[n-1]=1;
        RREP(i,n-1) {
            int u=tpsort[i];
            if(u==del) continue;
            for(auto [v,w]:g[u]) {
                if(v==del) continue;
                if(ldis[v]==ldis[u]+w) cntr[u]=(cntr[u]+cntr[v])%mod;
            }
        }
        if(ldis[n-1]<0) cout<<"-1\n";
        else cout<<ldis[n-1]<<' '<<cntr[0]<<'\n';
    }
    cout<<"-1\n";
    return 0;
}
