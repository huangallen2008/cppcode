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
const int maxv=2e6+5;
const int inf=1e9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
// bitset<maxv> isp;
Vi mnf(maxv);
void init_isp() {
    for(int i=2;i*i<maxv;i++) if(mnf[i]==0) for(int j=i;j<maxv;j+=i) if(mnf[j]==0) mnf[j]=i;
}
struct BIT {
    int n;
    Vi b;
    BIT() {}
    void init(int _n) {
        n=_n;
        b=Vi(n+1);
    }
    void ud(int u,int v) {
        u++;
        for(;u<=n;u+=u&-u) b[u]+=v;
    }
    int qu(int u) {
        u++;
        int r=0;
        for(;u>0;u-=u&-u) r+=b[u];
        return r;
    }
};
signed main() {
    IOS();
    init_isp();
    int n;
    cin>>n;
    Vi a(n);
    REP(i,n) cin>>a[i];
    // oparr(a)
    int V=2000;
    vector<BIT> bit(V);
    Vi mnp,cnt1(maxv);
    for(int i=2;i<V;i++) if(mnf[i]==i) {
        if(i<V) {
            bit[mnp.size()].init(25);
            mnp.pb(i);
        }
    }
    int an=0,sum=0;
    // ope(mnp.size())
    REP(i,n) {
        int x=a[i];
        an+=sum;
        while(x>1) {
            int f=mnf[x];
            int cc=0;
            while(x%f==0) {
                x/=f;
                cc++;
            }
            if(f>=V) {
                an-=cnt1[f],cnt1[f]++,sum++;
            }
        }
        // op(i)op(sum)ope(an)
    }
    reverse(ALL(a));
    REP(i,n) {
        int x=a[i];
        // x=a[i];
        REP(j,223) {
            int f=mnp[j];
            // #ifdef LOCAL
            // if(f>2) break;
            // #endif
            // op(i)ope(f)
            int cc=0;
            while(x%f==0) {
                x/=f;
                cc++;
            }
            assert(cc>=25);
            an+=bit[j].qu(cc-1);
            bit[j].ud(cc,1);
            // ope("pl")
            // REP(j,22) cout<<bit[j].qu(j+1)-bit[j].qu(j)<<' ';entr
            // op(i)op(x)op(f)op(cc)ope(an)
        }
        // ope(an)
    }
    cout<<an<<'\n';
    return 0;
}