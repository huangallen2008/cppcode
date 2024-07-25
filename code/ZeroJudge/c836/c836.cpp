#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int inf=(1ll<<62)-1;
const int maxn=2e5+5;
const int mod=1e9+7;
signed main()
{
    IOS();
    int n,m;
    cin>>n>>m;
//    vector<vector<int>> an1(n,vector<int>(n)),an2(n,vector<int>(n));
    vector<bitset<10000>> an1(n),an2(n);
    vector<vector<int>> g1(n),g2(n);
    vector<int> t(n),ts;
    REP(i,m) {
        int u,v;
        cin>>v>>u;
        v--,u--;
        g1[u].pb(v);
        g2[v].pb(u);
        t[v]++;
    }
    REP(i,n) an1[i][i]=1;
    REP(i,n) an2[i][i]=1;
    queue<int> q;
    REP(i,n) if(t[i]==0) q.push(i);
    while(q.size()) {
        int u=q.front();
        q.pop();
        ts.pb(u);
        for(int v:g1[u]) {
            t[v]--;
            if(t[v]==0) q.push(v);
        }
    }
    REP(i,n) {
        int u=ts[i];
        for(int v:g2[u]) an1[u]|=an1[v];
    }
    RREP(i,n) {
        int u=ts[i];
        for(int v:g1[u]) an2[u]|=an2[v];
    }
    REP(i,n) cout<<an1[i].count()<<" "<<n+1-an2[i].count()<<"\n";
    return 0;
}
