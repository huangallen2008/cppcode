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
const int inf=(1ll<<63)-1;
const int maxn=1e5+5;
const int mod=1e9+7;
signed main()
{
    IOS();
    int an=0;
    int n,m,k;
    cin>>n>>m>>k;
    int t;
    cin>>t;
    vector<bool> key(n,0);
    vector<vector<int>> o(n,vector<int>(k)),h(n,vector<int>(k));
    vector<bool> iso(n,0);
    vector<vector<int>> u(n);
    REP(i,t) {
        int x;
        cin>>x;
        key[x]=1;
    }
    REP(i,n) REP(j,k) cin>>o[i][j];
    REP(i,n) REP(j,k) cin>>h[i][j];
    REP(i,n) REP(j,k) u[o[i][j]].pb(i);
    queue<int> q;
    REP(i,n) {
        if(key[i]) {
            REP(j,u[i].size()) q.push(u[i][j]);
        }
    }
    while(q.size()) {
        int x=q.front();
        q.pop();
//        cout<<x<<" ";
        if(iso[x]) continue;
        bool ok=1;
        REP(i,k) if(!key[o[x][i]]) ok=0;
        if(ok) {
            an++;
            iso[x]=1;
            REP(i,k) key[h[x][i]]=1;
            REP(i,k) for(auto c:u[h[x][i]]) q.push(c);
//            cout<<"ok\n";
        }
//        else cout<<"nok\n";
    }
    cout<<an<<"\n";
    return 0;
}
