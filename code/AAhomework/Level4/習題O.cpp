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
const int mod=998244353;
const int maxn=2e6+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
signed main() {
    IOS();
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> deg(n);
    Graph g(n);
    REP(i,m) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        deg[u]++,deg[v]++;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<bool> rm(n);
    queue<int> q;
    REP(i,n) {
        if(deg[i]<k) {
            q.push(i);
            rm[i]=1;
        }
    }
    while(q.size()) {
        int u=q.front();
        q.pop();
        for(int v:g[u]) {
            if(rm[v]) continue;
            deg[v]--;
            if(deg[v]<k) {
                rm[v]=1;
                q.push(v);
            }
        }
    }
    int cnt=0;
    REP(i,n) cnt+=rm[i];
    cout<<cnt<<'\n';
    return 0;
}
