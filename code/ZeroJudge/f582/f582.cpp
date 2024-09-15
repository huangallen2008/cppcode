#include<bits/stdc++.h>
using namespace std;
//#define int long long
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
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (x%mod+mod)%mod
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
const int inf=(1ll<<62);
const int maxn=1e6+5;
const int mod=1e9+7;
int id(char c) {
    if(c=='A') return 1;
    if(c=='U') return 2;
    if(c=='C') return 4;
    if(c=='G') return 8;
    if(c=='@') return 15;
}
int n,k;
vector<int> g[1000];
//Graph g;
//vector<vector<int>> s;
int s[1000][80];
int dfs(int u) {
//    vector<vector<int>> cnt(k,vector<int>(4));
    if(g[u].size()==0) return 0;
    int cnt[80][4];
    REP(i,k) REP(j,4) cnt[i][j]=0;
    int an=0;
    for(int v:g[u]) {
        an+=dfs(v);
        REP(i,k) {
            REP(j,4) if((s[v][i]>>j)&1) cnt[i][j]++;
        }
    }
    int mx=0;
    REP(i,k) {
        if(s[u][i]==15) {
            s[u][i]=0;
            int mx=0;
            REP(j,4) mx=max(mx,cnt[i][j]);
            REP(j,4) {
                if(mx==cnt[i][j]) {
                    s[u][i]=(s[u][i]|(1<<j));
                }
            }
            an+=g[u].size()-mx;
        }
        else {
            REP(j,4) if((s[u][i]>>j)&1) an+=g[u].size()-cnt[i][j];
        }
    }
    return an;
}
signed main() {
    IOS();
    cin>>n>>k;
//    g=Graph(n);
//    s=vector<vector<int>>(n,vector<int>(k));
//    d=vector<vector<int>>(n,vector<int>(k));
    int root=0;
    REP(i,n) {
        int u,l;
        cin>>u>>l;
        u--,l--;
        REP(j,k) {
            char c;
            cin>>c;
            s[u][j]=id(c);
        }
        if(l!=u) g[l].pb(u);
        else root=u;
    }
    int an=dfs(root);
    cout<<an<<'\n';
    return 0;
}
