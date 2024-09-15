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
    int n;
    int s,t;
    cin>>n;
    vector<vector<int>> m(n,vector<int>(n));
    REP(i,n) REP(j,n) cin>>m[i][j];
    cin>>s>>t;
    s--,t--;
    queue<int> q;
    vector<int> d(n,-1);
    d[s]=0;
    q.push(s);
    while(q.size()) {
        int u=q.front();
        if(u==t) break;
        q.pop();
        REP(i,n) {
            if(m[u][i]==1) {
                if(d[i]>=0) continue;
                d[i]=d[u]+1;
                q.push(i);
            }
        }
    }
    cout<<d[t]<<"\n";
    return 0;
}
