#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define int long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
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
#define md(x) (((x)%(mod)+(mod))%(mod))
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";REP(idd,(x).size()) cout<<x[idd]<<" ";cout<<endl;
#define entr cout<<endl;
const int inf=(1ll<<62);
const int maxn=6e5+5;
const int mod=1e9+7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct Edge {
    int u,v,d;
};
struct Ord {
    int l,r,v;
};
void output(int n,int s) {
    REP(i,n) {
        int r=min(s,(int)9);
        cout<<r;
        s-=r;
    }
}
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    vector<Edge> edges;
    vector<int> ind;
    vector<Ord> ord0,ord1;
    REP(i,m) {
        int opt,l,r,v;
        cin>>opt>>l>>r>>v;
        ind.pb(l-1),ind.pb(r);
        if(opt==0) ord0.pb({l,r,v});
        else ord1.pb({l,r,v});
    }
    ind.pb(0),ind.pb(n);
    sort(ALL(ind));
    ind.erase(unique(ALL(ind)),ind.end());
    edges.pb({0,1,9*ind[1]});
    edges.pb({1,0,-1});
    REP1(i,ind.size()-2) {
        edges.pb({i,i+1,9*(ind[i+1]-ind[i])});
        edges.pb({i+1,i,0});
    }
    for(auto [l,r,v]:ord0) {
        l=lower_bound(ALL(ind),l)-ind.begin();
        r=lower_bound(ALL(ind),r)-ind.begin();
        edges.pb({l-1,r,v});
    }
    for(auto [l,r,v]:ord1) {
        l=lower_bound(ALL(ind),l)-ind.begin();
        r=lower_bound(ALL(ind),r)-ind.begin();
        edges.pb({r,l-1,-v});
    }
    shuffle(ALL(edges),rng);
    vector<int> dis(ind.size(),inf);
    dis[0]=0;
    int rd=ind.size();
    while(rd--) {
        bool ok=0;
        REP(i,edges.size()) {
            auto [u,v,d]=edges[i];
            if(dis[v]>dis[u]+d) {
                dis[v]=dis[u]+d;
                ok=1;
            }
        }
        if(rd==0&&ok) {
            cout<<"-1\n";
            return 0;
        }
        if(!ok) break;
    }
    REP(i,ind.size()-1) output(ind[i+1]-ind[i],dis[i+1]-dis[i]);
    cout<<'\n';
    return 0;
}
