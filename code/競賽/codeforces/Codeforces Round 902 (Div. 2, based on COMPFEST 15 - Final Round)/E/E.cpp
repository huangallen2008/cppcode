#include<bits/stdc++.h>
using namespace std;
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
const int maxn=2e5+5;
const int mod=998244353;
void solve() {
    int n;
    cin>>n;
    vector<int> a(n+1),ind(n+1);
    Graph g(n+1);
    REP1(i,n) {
        cin>>a[i];
        g[a[i]].pb(i);
        ind[a[i]]++;
    }
    vector<int> ina(n+1);
    vector<bool> inc(n+1,1);
    queue<int> q;
    REP1(i,n) {
        if(ind[i]==0) {
            q.push(i);
        }
    }
    while(q.size()) {
        int u=q.front();
        q.pop();
        inc[u]=0;
        ind[a[u]]--;
        if(ind[a[u]]==0) q.push(a[u]);
    }


    REP1(i,n) {
        if(g[i].size()==0) {
            q.push(a[i]);
            ina[a[i]]=1;
        }
    }
    while(q.size()) {
        int u=q.front();
        q.pop();
        if(inc[u]) continue;
        if(ina[u]==1) {
            if(ina[a[u]]==1) continue;
            q.push(a[u]);
        }
        else {
            ina[a[u]]=1;
            q.push(a[u]);
        }
    }
    vector<bool> vis(n+1);
    bool ok=1;
    REP1(i,n) {
        if(inc[i]&&ina[i]&&!vis[i]) {
            int ni=i;
            vis[ni]=1;
            i=a[i];

            while(i!=ni) {
                vis[i]=1;
                if(ina[i]==1) {
                    ok=0;
                    break;
                }
                ina[a[i]]=1;
                i=a[a[i]];
            }
            if(ok==0) break;
        }
    }
    vector<int> t(n+1);
    REP1(i,n) {
        if(inc[i]) t[a[i]]=i;
    }
//    REP1(i,n) cout<<t[i]<<" ";cout<<"\n";
    REP1(i,n) {
        if(inc[i]&&!vis[i]) {
//                cout<<i<<"!!!!!\n";
            int ni=i;
            vis[ni]=1;
            ina[ni]=1;
            i=a[i];
            int c=1;
            while(i!=ni) {
                c++;
        vis[i]=1;
                if(ina[t[i]]==0) ina[i]=1;
                i=a[i];
            }

            if(c%2==1) {
                    ok=0;break;}
        }
    }
    if(ok){
            vector<int> an;
        REP1(i,n) if(!ina[i]) an.pb(a[i]);
        cout<<an.size()<<"\n";
        REP(i,an.size()) cout<<an[i]<<" ";
        cout<<"\n";
    }
    else cout<<"-1\n";
}
signed main() {
    IOS();
//    int T;
//    cin>>T;
//    while(T--) {
        solve();
//    }
    return 0;
}
