#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,(n)+1)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int inf=(1ll<<62);
const int maxn=1e6+5;
const int mod=1e9+7;
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    Graph g(n);
    vector<int> ind(n);
    REP(i,m) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        ind[v]++;
    }
    vector<int> tpsort;
    queue<int> q;
    REP(i,n) if(ind[i]==0) q.push(i);
    while(q.size()) {
        int u=q.front();
        q.pop();
        tpsort.pb(u);
        for(int v:g[u]) {
            ind[v]--;
            if(ind[v]==0) q.push(v);
        }
    }
    if(tpsort.size()<n) cout<<"IMPOSSIBLE\n";
    else {
        REP(i,n) cout<<tpsort[i]+1<<" ";
        cout<<"\n";
    }
    return 0;
}
