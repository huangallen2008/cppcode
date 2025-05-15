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
const int maxn=1e6+5;
const int maxb=30;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int qur(int l,int r) {
    cout<<l<<' '<<r<<endl;
    int ret;
    cin>>ret;
    if(ret==0) exit(ret);
    return ret;
}
struct BIT {
    int n;
    Vi b;
    int lg;
    void init(int _n) {
        n=_n;
        b=Vi(n+1);
        lg=__lg(n)+1;
    }
    void ud(int u,int v) {
        for(;u<=n;u+=u&-u) b[u]+=v;
    }
    int kth(int k) {
        int now=0;
        RREP(i,lg) {
            if(now+(1<<i)<=n&&b[now+(1<<i)]<k) {
                now+=1<<i;
                k-=b[now];
            }
        }
        return now+1;
    }
};
signed main() {
    IOS();
    int n;
    cin>>n;
    if(n==1) {
        qur(1,1);
        return 0;
    }
    Vi ret(n+2);
    for(int i=n;i>=2;i--) ret[i]=qur(1,i);
    ret[n+1]=(n*(n-1)>>1)-ret[n];
    ret[1]=ret[2];
    Vi rk(n+1);
    for(int i=n;i>1;i--) rk[i]=ret[i+1]-ret[i-1]+i+1>>1;
    rk[1]=1;
    BIT bit;
    bit.init(n);
    REP1(i,n) bit.ud(i,1);
    Vi a(n+1);
    RREP1(i,n) {
        a[i]=bit.kth(rk[i]);
        bit.ud(a[i],-1);
    }
    REP1(i,n) {
        int id;
        for(int j=i;j<=n;j++) if(a[j]==i) id=j;
        if(id==i) continue;
        qur(i,id);
        reverse(a.begin()+i,a.begin()+id+1);
    }
    return 0;
}
