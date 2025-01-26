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
const int maxv=1e6+5;
const int maxn=1e3+5;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
Vpii dir={{1,0},{0,1},{-1,0},{0,-1}};
// Vpii dir={{0,0},{-1,1},{-2,0},{-1,-1}};
signed main() {
    IOS();
    int h,w;
    cin>>h>>w;
    vector<vector<char>> a(h,vector<char>(w));
    Vi dr(h);
    REP(i,h) {
        REP(j,w) {
            cin>>a[i][j];
            if(a[i][j]=='R') dr[i]=1;
        }
    }
    struct S{
        int x,y,t;
    };
    queue<S> q;
    vector<Vi> dis(h,Vi(w,inf));
    dis[0][0]=0;
    q.push({0,0,0});
    auto ncc=[&](int x,int y,int t) {
        if(dr[x]) return a[x][((y-t)%w+w)%w];
        else return a[x][(y+t)%w];
    }
    auto nco=[&](int x,int y,int t) {
        // if(dr[x]) return a[x][((y-t)%w+w)%w]=='.';
        // else 
        return ncc(x,y,t)=='.';
    };
    vector<vector<Vi>> vis(h,vector<Vi>(w,Vi(w)));
    while(q.size()) {
        auto [x,y,t]=q.front();
        vis[x][y][t%w]=1;
        op(x)op(y)ope(dis[x][y])
        REP(i,h) {
            REP(j,w) cout<<ncc(i,j,t);cout<<'\n';
        }entr
        q.pop();
        for(auto [dx,dy]:dir) {
            int nx=x+dx,ny=y+dy;
            nx=(nx+h)%h;
            ny=(ny+w)%w;
            if(nco(nx,ny,t+1)) {
                chmin(dis[nx][ny],t+1);
                if(!vis[nx][ny][(t+1)%w])q.push({nx,ny,t+1});
            }
        }
    }
    #ifdef LOCAL_
    REP(i,h) {
        REP(j,w) cout<<dis[i][j]<<' ';entr
    }
    #endif
    REP(i,h) {
        REP(j,w) {
            if(dis[i][j]==inf) cout<<'-';
            else cout<<dis[i][j]%10;
        }
        cout<<'\n';
    }
    return 0;
}