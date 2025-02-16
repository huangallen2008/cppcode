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
const int maxn=1e6+5;
const int inf=1ll<<60;
const int sn=200;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct S {
    int n;
    vector<vector<int>> mn,mx,md;
    S(){}
    S(Vpii a) {
        n=a.size();
        mn=mx=md=vector<Vi>(n);
        oparr(a)
        REP(i,n-1) mn[i][i+1]=mx[i][i+1]=a[i].f,md[i][i+1]=inf;
        REP(i,n){
            REP(j,i-1) {
                mn[i][j]=min(mn[i][j-1],mn[i+1][j]);
                mx[i][j]=max(mx[i][j-1],mx[i+1][j]);
                md[i][j]=min({md[i][j-1],md[i+1][j],abs(a[i].f-a[j].f)});
            }
        }
    }
    int qu_mn(int l,int r) { return mn[l][r]; } 
    int qu_mx(int l,int r) { return mx[l][r]; } 
    int qu_md(int l,int r) { return md[l][r]; } 
};
signed main() {
    IOS();
    int n,q;
    cin>>n>>q;
    Vpii a(n);
    REP(i,n) cin>>a[i].f,a[i].s=i;
    sort(ALL(a));
    vector<S> b;
    vector<Vi> rk;
    for(int i=0;i<n;i+=sn) {
        vector<pii> t;
        for(int j=i;j<i+sn&&j<n;j++) t.pb(a[j]);
        sort(ALL(t),[&](pii a,pii b){
            return a.s<b.s;
        });
        int sz=t.size();
        b.pb(S(t));
        ope(i)
        Vi r(n);
        int it=0;
        REP(j,n) {
            while(it<sz&&t[it].s<j) it++;
            r[j]=it;
        }
        rk.pb(r);
    }
    int cnt=b.size();
    int last=0;
    REP(i,q) {
        int l,r;
        cin>>l>>r;
        l=(l+last)%n;
        r=(r+last)%n;
        int an=inf;
        int pmx=-inf;
        REP(j,cnt) {
            int li=rk[j][l],ri=rk[j][r+1]-1;
            chmin(an,b[j].qu_md(li,ri));
            chmin(an,b[j].qu_mn(li,ri)-pmx);
            pmx=b[j].qu_mx(li,ri);
        }
        last=an;
        cout<<an<<'\n';
    }
    return 0;
}