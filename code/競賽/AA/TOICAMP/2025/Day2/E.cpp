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
const int maxv=1e12+5;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int r,c,k;
vector<Vi> a;
vector<pipii> s;
Vpii dir={{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0}};
bool ok(int x,int y) {
    return !(x<0||x>=r||y<0||y>=c);
}
int check(int m) {
    vector<Vi> d=a,vis(r,Vi(c));
    // priority_queue<pipii> pq;
    int it=1;
    queue<pii> q;
    q.push(s[0].s);
    // REP(i,r) REP(j,c) pq.push({a[i][j],{i,j}});
    while(q.size()) {
        auto [x,y]=q.front();
        while(it<r*c&&a[s[it].s.f][s[it].s.s]>=a[x][y]) q.push(s[it++].s);
        continue;
        q.pop();
        if(vis[x][y]) continue;
        vis[x][y]=1;
        for(auto [dx,dy]:dir) {
            int nx=x+dx,ny=y+dy;
            if(!ok(nx,ny)) continue;
            if(d[nx][ny]<d[x][y]-m) {
                d[nx][ny]=d[x][y]-m;
                q.push({nx,ny});
            }
        }
    }
    int an=0;
    REP(i,r) REP(j,c) an+=d[i][j]-a[i][j];
    return an;
}
signed main() {
    IOS();
    cin>>r>>c>>k;
    a=vector<Vi>(r,Vi(c));
    REP(i,r) REP(j,c) cin>>a[i][j],s.pb({a[i][j],{i,j}});
    sort(ALL(s),greater<pipii>());
    int l=0,r=maxv,m;
    while(l<r) {//first m: check(m)<=k
        m=l+r>>1;
        op(l)op(r)ope(m)
        if(check(m)<=k) r=m;
        else l=m+1;
    }
    cout<<l<<'\n';
    return 0;
}