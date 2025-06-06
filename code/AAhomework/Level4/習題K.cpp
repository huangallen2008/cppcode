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
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
const int mod=1e9+7;
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
vector<int> g[maxn][26];
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    REP(i,m) {
        int u,v;
        char c;
        cin>>u>>v>>c;
        u--,v--;
        g[u][c-'a'].pb(v);
        g[v][c-'a'].pb(u);
    }
    queue<vector<int>> q;
//    vector<int> dis(n,inf);
    vector<bool> vis(n);
    vis[0]=1;
//    dis[0]=0;
    vector<char> an(n);
    q.push({0});
    while(q.size()) {
        vector<int> uv=q.front();
        q.pop();
        vector<vector<int>> t(26);
        REP(ch,26) {
            for(int u:uv) {
                for(int v:g[u][ch]) {
//                    if(dis[v]!=inf) continue;
                    if(vis[v]) continue;
                    vis[v]=1;
                    t[ch].pb(v);
                    an[v]='a'+ch;
//                    dis[v]=dis[u]+1;
                }
            }
        }
        REP(i,26) if(t[i].size()) q.push(t[i]);
    }
    for(int i=1;i<n;i++) cout<<an[i];
    cout<<'\n';
    return 0;
}
