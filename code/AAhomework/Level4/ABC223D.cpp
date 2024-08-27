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
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    Graph g(n);
    vector<int> ind(n);
    REP(i,m) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        ind[v]++;
    }
    vector<int> tp_sort;
    priority_queue<int,vector<int>,greater<int>> q;
    REP(i,n) if(ind[i]==0) q.push(i);
    while(q.size()) {
        int u=q.top();
        q.pop();
        tp_sort.pb(u);
        for(int v:g[u]) {
            ind[v]--;
            if(ind[v]==0) q.push(v);
        }
    }
    if(tp_sort.size()<n) cout<<"-1\n";
    else {
        REP(i,n) cout<<tp_sort[i]+1<<' ';
        cout<<'\n';
    }
    return 0;
}
