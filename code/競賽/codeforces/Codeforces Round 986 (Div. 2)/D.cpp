#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("Ofast,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
#define int long long
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<=(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define ALL1(x) (x).begin()+1,(x).end()
#define SZ(x) (int)((x).size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define Graphw vector<vector<pii>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#define MD(x,M) (((x)%(M)+(M))%(M))
#define ld long double
#define pdd pair<ld,ld>
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define addmod(x,y) x=((x+(y))%mod)
#define Vi vector<int>
#ifdef LOCAL_
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";for(auto &mken:(x)) cout<<mken<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=30011;
const int maxn=1e6+5;
const int maxc=26;
const int maxb=20;
const int inf=(1ll<<62); 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
void solve() {
    int n;
    cin>>n;
    Vi a(n),b(n),c(n);
    REP(i,n) cin>>a[i];
    REP(i,n) cin>>b[i];
    REP(i,n) cin>>c[i];
    // Vi stk;
    vector<pii> stk;
    Graphw g(n);
    RREP(i,n) {
        while(stk.size()&&stk.back().f<a[i]) {
            //add edge i->stk.back().s
            g[i].pb({stk.back().s,0});
            stk.pop_back();
        }
        stk.pb({a[i],i});
    }
    ope("ok")
    stk.clear();
    RREP(i,n) {
        while(stk.size()&&stk.back().f<b[i]) {
            //add edge i->stk.back().s
            g[i].pb({stk.back().s,1});
            stk.pop_back();
        }
        stk.pb({b[i],i});
    }
    stk.clear();
    RREP(i,n) {
        while(stk.size()&&stk.back().f<c[i]) {
            //add edge i->stk.back().s
            g[i].pb({stk.back().s,2});
            stk.pop_back();
        }
        stk.pb({c[i],i});
    }
    Vi dis(n,inf);
    queue<int> q;
    q.push(0);
    Vi pre(n),val(n);
    while(q.size()) {
        int u=q.front();
        ope(u)
        q.pop();
        for(auto [v,w]:g[u]) {
            if(dis[v]>dis[u]+1) {
                dis[v]=dis[u]+1;
                pre[v]=u;
                val[v]=w;
            }
        }
    }
    if(dis[n-1]==inf) {
        cout<<"No\n";
        return;
    }
    cout<<"Yes\n";
    int t=n-1;
    vector<pii> an;
    while(t!=0) {
        an.pb({val[t],t});
        t=pre[t];
    }
    reverse(ALL(an));
    for(auto [x,y]:an) {
        if(y==0) cout<<"q ";
        if(y==1) cout<<"k ";
        if(y==2) cout<<"j ";
        cout<<x<<'\n';
    }
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}