#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,popcnt")
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
#define MD(x,M) (((x)%(M)+(M))%(M))
#define ld long double
#define pdd pair<ld,ld>
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";REP(allen,(x).size()) cout<<x[allen]<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();
    int a,b,n,qu;
    cin>>a>>b>>n>>qu;
    assert(qu<=10);
    // Graph g(n);
    // REP(i,n) {
    //     g[i].pb((i+a)%n);
    //     g[i].pb((i*b)%n);
    // }
    vector<int> dis;
    queue<int> q;
    REP(i,qu) {
        int x;
        cin>>x;
        dis=vector<int>(n,inf);
        dis[x]=0;
        q.push(x);
        while(q.size()) {
            int u=q.front();
            q.pop();
            // {
                int v1=(u+a)%n;
                if(dis[v1]>dis[u]+1) {
                dis[v1]=dis[u]+1;
                q.push(v1);}
            // }
            // {
                int v2=(u*b)%n;
                if(dis[v2]>dis[u]+1) {
                dis[v2]=dis[u]+1;
                q.push(v2);}
            // }
        }
        if(dis[1]==inf) cout<<"-1\n";
        else cout<<dis[1]<<'\n';
    }
    return 0;
}