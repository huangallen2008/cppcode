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
const int maxn=2e5+5;
const int mod=1e9+7;
signed main()
{
    IOS();
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n);
    vector<int> s(n),d(n);
    vector<bool> o(n,0);
    REP(i,m) {
        int x,y;
        cin>>x>>y;
        x--,y--;
        g[x].pb(y);
        g[y].pb(x);
        s[x]++;
        s[y]++;
    }
    int an=0;
    int c=1;
    REP(i,n) {
        if(d[i]==0) {
            queue<int> q;
            q.push(i);
            d[i]=c;
            while(q.size()) {
                int u=q.front();
                q.pop();
                for(auto v:g[u]) {
                    if(d[v]==0) {
                        d[v]=c;
                        q.push(v);
                    }
                }
            }
            c++;
        }
    }
    REP1(cc,c-1) {
        while(1) {
            vector<pii> t;
            REP(i,n) if(!o[i]&&d[i]==cc) t.pb({s[i],i});
            if(t.size()==0) break;
            sort(ALL(t));
            int mn=t[0].f;
            an=max(an,mn*SZ(t));
            REP(i,n) {
                if(t[i].f==mn) {
                    o[t[i].s]=1;
                    for(auto k:g[t[i].s]) {
                        s[k]--;
                    }
                }
                else break;
            }
        }
    }
    cout<<an<<"\n";
    return 0;
}
