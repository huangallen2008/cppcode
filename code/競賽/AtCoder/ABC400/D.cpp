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
#define SZ(x) ((int)((x).size()))
#define SQ(x) ((x)*(x))
#define pii pair<int,int>
#define pipii pair<int,pii>
#define ppi pair<pii,int>
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
const int mod=1e9+7;
const int maxn=2e5+5;
const int maxv=1300;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();
    int h,w;
    cin>>h>>w;
    vector<Vi> a(h,Vi(w));
    REP(i,h) {
        REP(j,w) {
            char c;
            cin>>c;
            a[i][j]=c=='.';
        }
    }
    int sx,sy,ex,ey;
    cin>>sx>>sy>>ex>>ey,sx--,sy--,ex--,ey--;
    Vpii dir={{0,1},{0,-1},{1,0},{-1,0}};
    auto nok=[&](int x,int y) ->bool{ return x<0||y<0||x>=h||y>=w; };
    vector<Vi> dis(h,Vi(w,inf));
    deque<pii> dq;
    dis[sx][sy]=0;
    dq.pb({sx,sy});
    while(SZ(dq)) {
        auto [x,y]=dq.front();
        dq.pop_front();
        for(auto [dx,dy]:dir) {
            int nx=x+dx,ny=y+dy;
            if(nok(nx,ny)) continue;
            if(a[nx][ny]) {
                if(dis[nx][ny]>dis[x][y]) {
                    dis[nx][ny]=dis[x][y];
                    dq.push_front({nx,ny});
                }
            }else {
                if(dis[nx][ny]>dis[x][y]+1) {
                    dis[nx][ny]=dis[x][y]+1;
                    dq.pb({nx,ny});
                }
                int nx2=nx+dx,ny2=ny+dy;
                if(nok(nx2,ny2)) continue;
                if(dis[nx2][ny2]>dis[x][y]+1) {
                    dis[nx2][ny2]=dis[x][y]+1;
                    dq.pb({nx2,ny2});
                }
            }
        }
    }
    int an=dis[ex][ey];
    cout<<an<<'\n';
    return 0;
}
