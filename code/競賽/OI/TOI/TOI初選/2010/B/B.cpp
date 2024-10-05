#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n+1)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const ll inf=(1ll<<63)-1;
const int maxn=1e4+5;
const ll mod=1e9+7;
struct DSC {
    int n;
    Graph g;
    vector<int> r,an,t,in;
    DSC(int _n,Graph _g,vector<int> _r,vector<int> _t,vector<int> _in) {
        n=_n; g=_g; r=_r; t=_t; in=_in;
        an=vector<int>(n);
    }
    void bfs() {
        queue<pii> q;
        REP(i,SZ(r)) {
            q.push({r[i],t[r[i]]});
        }
        while(q.size()) {
            int u=q.front().f,d=q.front().s;
            q.pop();
            if(d>an[u]) {
                an[u]=d;
                for(auto v:g[u]) q.push({v,d+t[v]});
            }
        }
    }
    int get_an() {
        bfs();
        return *max_element(ALL(an));
    }
};
signed main()
{
    IOS();
    int n;
    int T;
    cin>>T;
    while(T--) {
        cin>>n;
        vector<int> r,in(n);
        Graph g=Graph(n);
        vector<int> t(n);
        REP(i,n) {
            int x,y;
            cin>>t[i]>>x;
            REP(j,x) {
                cin>>y;
                y--;
                in[y]=1;
                g[i].pb(y);
            }
        }
        REP(i,n) if(in[i]==0) r.pb(i);
        DSC dsc(n,g,r,t,in);
        cout<<dsc.get_an()<<endl;
    }
    return 0;
}
