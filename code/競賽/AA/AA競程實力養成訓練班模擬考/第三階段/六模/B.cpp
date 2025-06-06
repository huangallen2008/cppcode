#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,sse4,bmi2,popcnt")
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
#define Vpii vector<pii>
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) {cout<<(#x)<<":";for(auto allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;}
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
template<typename T1,typename T2>
ostream& operator<<(ostream& os,pair<T1,T2> p) { return os<<'{'<<p.f<<','<<p.s<<'}'; }
template<typename T1,typename T2>
istream& operator>>(istream& os,pair<T1,T2> &p) { return os>>p.f>>p.s; }
template<typename S>
ostream& operator<<(ostream& os,vector<S> p) { for(auto allen:p) os<<allen<<' ';return os<<'\n'; }
template<typename S>
istream& operator>>(istream& os,vector<S> &p) { for(auto &allen:p) os>>allen;return os; }
template<typename T1,typename T2>
pair<T1,T2> operator+(pair<T1,T2> p1,pair<T1,T2> p2) { return pair<T1,T2>(p1.f+p2.f,p1.s+p2.s); }
const int mod=998244353;
const int maxn=5;
const int maxb=64;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();
    int n,m,k;
    cin>>n>>m>>k;
    k++;
    Graph g(n+1);
    Vi c(n+1);
    for(int i=2;i<=n;i++) cin>>c[i];
    REP(i,m) {
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<Vi> dis(n+1,Vi(n+1,inf));
    REP1(i,n) {
        dis[i][i]=0;
        queue<int> q;
        Vi vis(n+1);
        vis[i]=1;
        q.push(i);
        while(q.size()) {
            int u=q.front();
            q.pop();
            for(int v:g[u]) {
                if(vis[v]) continue;
                vis[v]=1;
                dis[i][v]=dis[i][u]+1;
                q.push(v);
            }
        }
    }
    vector<Vi> d2(n+1,Vi(n+1));
    REP1(i,n) {
        REP1(j,n) {
            if(i==1||j==1||i==j||dis[1][i]>k||dis[i][j]>k) d2[i][j]=-inf;
            else {
                d2[i][j]=c[i]+c[j];
            }
        }
        // oparr(d2[i])
    }
    vector<Vpii> mx(n+1,Vpii(3,{-inf,-1}));
    auto upd=[&](Vpii &a,pii x)->void {
        // op(a)op(x)
        REP(i,3) {
            if(x.f>a[i].f) {
                for(int j=2;j>i;j--) a[j]=a[j-1];
                a[i]=x;
                break;
            }
        }
        // ope(a)
    };
    REP1(i,n) {
        for(int j=2;j<=n;j++) {
            // ope(i)
            if(i==j) continue;
            upd(mx[i],{d2[j][i],j});
        }
    }
    // oparr(mx)
    int an=0;
    REP1(i,n) {
        REP1(j,n) {//1,mx[i],i,j,mx[j],1
            if(i==1||j==1||i==j||dis[i][j]>k) continue;
            REP(i1,3) REP(i2,3) {
                pii p1=mx[i][i1],p2=mx[j][i2];
                // op(i)op(j)op(p1.s)ope(p2.s)
                if(p1.s==-1||p2.s==-1||p1.s==j||p2.s==i||p1.s==p2.s) continue;
                chmax(an,p1.f+p2.f);
            }
        }
    }
    cout<<an<<'\n';
    return 0;
}