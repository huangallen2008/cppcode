#include <bits/stdc++.h>
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
#define md(x) (x%mod+mod)%mod
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define op(x) cout<<#x<<"="<<x<<endl;
#define opa(x) cout<<#x<<": [";REP(i,x.size())cout<<x[i]<<" ";cout<<"] size:"<<x.size()<<endl;
const int inf=(1ll<<62)-1;
const int maxn=1e5+5;
const int mod=1e9+7;
int n,m;
vector<vector<pii>> g;
struct edge {
    int v,d,id;
};
vector<vector<edge>> og;
bool check(int c) {
    Graph ng(n);
    REP(i,n) REP(j,g[i].size()) if(g[i][j].s>c) ng[i].pb(g[i][j].f);
    vector<int> ind(n);
    REP(i,n) REP(j,ng[i].size()) ind[ng[i][j]]++;
//    opa(ind)
    queue<int> q;
    vector<int> tp_sort;
    REP(i,n) if(ind[i]==0) q.push(i);
//    op(q.size())
    while(q.size()) {
        int u=q.front();
        q.pop();
        tp_sort.pb(u);
        for(int v:ng[u]) {
            ind[v]--;
            if(ind[v]==0) q.push(v);
        }
    }
//    cout<<c<<":"<<tp_sort.size()<<endl;
    if(tp_sort.size()<n) return 0;
    else return 1;
}
void out(int c) {
    Graph ng(n);
    REP(i,n) REP(j,g[i].size()) if(g[i][j].s>c) ng[i].pb(g[i][j].f);
    vector<int> ind(n);
    REP(i,n) REP(j,ng[i].size()) ind[ng[i][j]]++;
    queue<int> q;
    vector<int> tp_sort;
    REP(i,n) if(ind[i]==0) q.push(i);
    while(q.size()) {
        int u=q.front();
        q.pop();
        tp_sort.pb(u);
        for(int v:ng[u]) {
            ind[v]--;
            if(ind[v]==0) q.push(v);
        }
    }
    vector<int> an;
    vector<int> tp_id(n);
    REP(i,n) tp_id[tp_sort[i]]=i;
    REP(i,n) {
        REP(j,g[i].size()) {
            if(g[i][j].s<=c) {
                if(tp_id[i]>tp_id[g[i][j].f]) {
                    an.pb(og[i][j].id);
                }
            }
        }
    }
    cout<<c<<" "<<an.size()<<"\n";
    REP(i,an.size()) cout<<an[i]<<"\n";
    cout<<"\n";
}
main() {
    IOS();
    cin>>n>>m;
    g=vector<vector<pii>>(n);
    og=vector<vector<edge>>(n);
    REP(i,m) {
        int u,v,d;
        cin>>u>>v>>d;
        u--,v--;
        g[u].pb({v,d});
        og[u].pb({v,d,i+1});
    }
    int l=0,r=1e9+1,x;
    while(l<r) {
        x=(l+r)/2;
        if(check(x)) r=x;
        else l=x+1;
    }
    out(l);
    return 0;
}
