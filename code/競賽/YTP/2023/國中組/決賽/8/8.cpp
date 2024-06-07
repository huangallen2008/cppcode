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
const int inf=(1ll<<62);
const int maxn=1e5+5;
const int mod=1e9+9;
signed main()
{
    IOS();
    int n,m;
    cin>>n>>m;
    int s,e;
    vector<vector<int>> a(n,vector<int>(m)),g(n*m);
    REP(i,n) {
        REP(j,m) {
            char c;
            cin>>c;
            if(c=='#') a[i][j]=1;
            if(c=='S') s=i*m+j;
            if(c=='E') e=i*m+j;
        }
    }
    REP(i,n) {
        int l=-1;
        REP(j,m) {
            if(i*m+j==e) l=i*m+j;
            if(a[i][j]==1) l=-1;
            else {
                if(l==-1) l=i*m+j;
                else g[i*m+j].pb(l);
            }
        }
    }
    REP(i,n) {
        int l=-1;
        RREP(j,m) {
            if(i*m+j==e) l=i*m+j;
            if(a[i][j]==1) l=-1;
            else {
                if(l==-1) l=i*m+j;
                else g[i*m+j].pb(l);
            }
        }
    }
    REP(j,m) {
        int l=-1;
        REP(i,n) {
            if(i*m+j==e) l=i*m+j;
            if(a[i][j]==1) l=-1;
            else {
                if(l==-1) l=i*m+j;
                else g[i*m+j].pb(l);
            }
        }
    }
    REP(j,m) {
        int l=-1;
        RREP(i,n) {
            if(i*m+j==e) l=i*m+j;
            if(a[i][j]==1) l=-1;
            else {
                if(l==-1) l=i*m+j;
                else g[i*m+j].pb(l);
            }
        }
    }
    vector<int> d(n*m);
    queue<int> q;
    q.push(s);
    while(q.size()) {
        int u=q.front();
        q.pop();
        if(u==e) break;
        for(int v:g[u]) {
            if(d[v]==0) {
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
    if(d[e]==0) cout<<"-1\n";
    else cout<<d[e]<<"\n";
    return 0;
}
