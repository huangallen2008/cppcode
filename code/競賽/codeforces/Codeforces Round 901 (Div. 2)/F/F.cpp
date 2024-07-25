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
const int maxn=5e3+5;
const int mod=1e9+7;
struct D {
    int p,q;
    void pl(D b) {
        q=q*b.p+p*b.q;
        p*=b.p;
        int k=__gcd(p,q);
        p/=k;q/=k;
    }
};
void solve() {
    int n,m;
    cin>>n>>m;
    Graph g(n),gb(n);
    vector<bool> o(n);
    REP(i,m) {
        int x,y;
        cin>>x>>y;
        x--,y--;
        g[x].pb(y);
        gb[y].pb(x);
    }
    queue<int> q;
    q.push(n-1);
    o[n-1]=1;
    while(q.size()) {
        int u=q.front();
        q.pop();
        o[u]=1;
        for(int v:gb[u]) q.push(v);
    }
    vector<int> k(n);
    REP(i,n) {
        for(int v:g[i]) k[i]+=o[v];
    }
    vector<double> d(n);
    d[0]=1;
//    cout<<"K:";REP(i,n) cout<<k[i]<<" ";cout<<"\n";
    REP(i,n) {
        if(k[i]==0) continue;
        int t=g[i].size();
        int p=1,q=1;
        for(int j=0;j*2<t;j++) {
            p*=t-(j*2+1);
            q*=(t-j*2);
        }
//        cout<<"???????????/"<<p<<" "<<q<<endl;
        p=q-p;
        q*=k[i];
//        int gcd=__gcd(p,q);
//        p/=gcd;
//        q/=gcd;
        cout<<i<<" "<<p<<" "<<q<<"\n";
        for(int v:g[i]) {d[v]+=d[i]*((double)p/q);
        cout<<"d["<<v<<"]="<<d[v]<<"\n";}
    }
    cout<<fixed<<setprecision(9)<<d[n-1]<<"\n";
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}
