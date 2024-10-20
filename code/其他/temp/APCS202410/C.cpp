#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
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
#ifdef LOCAL
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
const int mod=1e9+7;
const int maxn=5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
vector<pii> dir={{0,1},{1,0},{0,-1},{-1,0}};
pii p;
int n,m,k;
vector<Vi> a;
bool ok(pii x) {
    if(x.f<0||x.f>=n||x.s<0||x.s>=m||a[x.f][x.s]==-1) return 0;
    return 1;
}
pii nxt(pii x,int dd)   {
    return {x.f+dir[dd].f,x.s+dir[dd].s};
}
signed main() {
    IOS(); 
    cin>>n>>m>>Q;
    vector<Vi> a(n,Vi(m));
    REP(i,n) REP(j,m) cin>>a[i][j];
    int r,c;
    REP(i,n) REP(j,m) if(a[i][j]==-1) r=i,c=j;
    int lb=0,rb=n*m,mb;
    while(lb<rb) {
        mb=lb+rb>>1;
        queue<pii> q;
        q.push({r,c});
        vector<Vi> o(n,Vi(m)),dis(n,Vi(m,inf));
        o[r][c]=1;
        vector<pii> stk;
        int re=0;
        while(q.size()) {
            auto [u,v]=q.front();
            queue<pii> qq;
            qq.push({u,v});
            dis[u][v]=0;
            stk.pb({u,v});
            while(qq.size()) {
                auto nn=qq.front();
                qq.pop();
                if(dis[nn.f][nn.s]>=(u==r&&v==c?mb:a[u][v])) {
                    continue;
                }
                REP(di,4) {
                    pii nnn=nxt(nn,di);
                    if(ok(nnn)&&a[nnn.f][nnn.s]!=-1&&dis[nnn.f][nnn.s]==inf) {
                        dis[nnn.f][nnn.s]=dis[nn.f][nn.s]+1;
                        qq.push(nnn);
                    }
                }
            }
            while(stk.size()) {
                auto [x,y]=stk.back();
                stk.pop_back();
                dis[x][y]=inf;
                if(!o[x][y]) {
                    o[x][y]=1;
                    q.push({x,y});
                }
            }
        }
        REP(i,n) REP(j,m) re+=o[i][j];
        if(re>=Q) rb=mb;
        else lb=mb+1;
    }
    cout<<lb<<'\n';
    return 0;
}