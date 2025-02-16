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
void solve() {
    int n,l,k;
    cin>>n>>l>>k;
    Vpii a(n);
    REP(i,n) cin>>a[i].f>>a[i].s;
    vector<Vi> s(n,Vi(n));//s[i][j]: how many k (k<=j) a[k].s+a[k].f<a[i].s+a[i].f
    vector<Vi> d(n,Vi(n));//d[i][j]: how many k (k<=j) a[k].s-a[k].f<a[i].s-a[i].f
    REP(i,n) {
        REP(j,n) {
            if(j)s[i][j]=s[i][j-1],d[i][j]=d[i][j-1];
            if(a[j].s+a[j].f<a[i].s+a[i].f) s[i][j]++;
            if(a[j].s-a[j].f<a[i].s-a[i].f) d[i][j]++;
        }
        oparr(s[i])
        oparr(d[i])
    }
    auto midx=[&](pii a,pii b) {
        return a.f+b.f+b.s-a.s>>1;
    };
    vector<Vi> mdx(n,Vi(n));
    REP(j,n) {
        REP(i,j) {
            mdx[i][j]=upper_bound(ALL(a),pii{midx(a[j],a[i]),inf})-a.begin()-1;
        }
    }
    vector<Vi> dp(k+1,Vi(n,-inf));
    auto cnsum=[&](int l,int r) ->int{ 
        if(l>r) return 0;
        return (l+r)*(r-l+1)>>1; 
    };
    auto qusum=[&](pii a,pii b) {
        int h1=a.s+b.s+b.f-a.f>>1;
        int h2=a.s+b.s+b.f-a.f-1>>1;
        return cnsum(a.s,h1)+cnsum(b.s,h2)-b.s;
    };
    auto ok=[&](pii a,pii b) {
        return abs(a.f-b.f)>=abs(a.s-b.s);
    };
    auto quh=[&](pii a,pii b,int x) {
        int mid=midx(a,b);
        if(x<=mid) return a.s+x-a.f;
        else return b.s+b.f-x;
    };
    REP(i,k+1) {
        REP(j,n) {
            int ht0=s[j][j];
            if(ht0<=i) chmax(dp[i][j],cnsum(a[j].s+1,a[j].s+a[j].f-1));
            op(i)op(ht0)ope(cnsum(a[j].s+1,a[j].s+a[j].f-1))
            REP(k,j) {
                if(!ok(a[k],a[j])) continue;
                // int mid=midx(a[k],a[j]);
                int mid=mdx[k][j];
                int ht=s[j][j]-s[j][mid]+d[k][mid]-d[k][k];
                op(i)op(j)op(k)op(a[k])op(a[j])op(mid)ope(ht)
                if(ht<=i) chmax(dp[i][j],dp[i-ht][j]+qusum(a[k],a[j]));
                if(ht<=i){op(dp[i-ht][j])ope(qusum(a[k],a[j]))}
            }
        }
        oparr(dp[i])
    }
    int an=0;
    REP(i,n) {
        int ht=d[i].back()-d[i][i];
        if(ht<=k) chmax(an,dp[k-ht][i]+cnsum(a[i].s,a[i].s+l-a[i].f));
        // op(i)op(ht)op(dp[k-ht][i])ope(cnsum(a[i].s,a[i].s+l-a[i].f));
    }
    cout<<an<<'\n';
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
/*
1
5 100000000 3
123 4567890
1234 567890
12345 67890
123456 7890
1234567 890

1
2 2 0
1 1
2 1


*/