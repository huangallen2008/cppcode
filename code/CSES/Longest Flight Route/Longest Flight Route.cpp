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
    vector<int> ind(n);
    Graph g(n);
    REP(i,m) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        ind[v]++;
    }
    vector<int> p(n),dis(n,-inf);
    dis[0]=0;
    queue<int> q;
    REP(i,n) if(ind[i]==0) q.push(i);
    while(q.size()) {
        int u=q.front();
        q.pop();
        for(int v:g[u]) {
            if(dis[v]<dis[u]+1) {
                dis[v]=dis[u]+1;
                p[v]=u;
            }
            ind[v]--;
            if(ind[v]==0) {
                q.push(v);
            }
        }
    }
    if(dis[n-1]<0) cout<<"IMPOSSIBLE\n";
    else {
        vector<int> an;
        an.pb(n-1);
        int t=n-1;
        while(t!=0) {
            t=p[t];
            an.pb(t);
        }
        cout<<an.size()<<"\n";
        RREP(i,an.size()) cout<<an[i]+1<<" ";
        cout<<"\n";
    }
    return 0;
}
