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
const int maxn=2e5+5;
const int maxb=20;
const int inf=1e9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
    int n,mm;
int st[maxb][maxn];
int rst[maxb][maxn];
Vi a,ra,pa,pra;
void init_st() {
    REP1(i,n) st[0][i]=a[i];
    REP1(i,n) rst[0][i]=ra[i];
    REP1(i,maxb-1) {
        REP1(j,n) {
            st[i][j]=max(st[i-1][j],st[i-1][min(j+(1<<i-1),n-1)]);
            rst[i][j]=max(rst[i-1][j],rst[i-1][min(j+(1<<i-1),n-1)]);
        }
    }
}
int qu(int l,int r) {
    if(l>r) return -inf;
    int lg=__lg(r-l+1);
    return max(st[lg][l],st[lg][r-(1<<lg)+1]);
}
int rqu(int l,int r) {
    int lg=__lg(r-l+1);
    return max(rst[lg][l],rst[lg][r-(1<<lg)+1]);
}
signed main() {
    IOS();
    cin>>n>>mm;
    a=Vi(n+1);
    REP1(i,mm) {
        int xx;cin>>xx>>xx;
        cin>>a[i];
    }
    pa=ra=a;
    reverse(ALL(ra));
    pra=ra;
    REP1(i,n-1) pa[i]=max(pa[i-1],a[i]);
    REP1(i,n-1) pra[i]=max(pra[i-1],ra[i]);
    init_st();
    int q;
    cin>>q;
    REP(i,q) {
        int s,t;
        cin>>s>>t;
        if(s<t) {
            int mx=qu(s,t-1);
            int l=1,r=s,m;
            while(l<r) {
                m=l+r>>1;
                if(qu(m,s-1)<mx) r=m;
                else l=m+1;
            }
            // ope(l)
            cout<<t-l<<'\n';
        }else {
            int mx=qu(t,s-1);
            int l=s,r=n,m;
            while(l<r) {
                m=l+r+1>>1;
                if(qu(s,m)<mx) l=m;
                else r=m-1;
            }
            ope(l)
            cout<<l-t+1<<'\n';
        }
    }

    return 0;
}