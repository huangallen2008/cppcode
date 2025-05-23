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
int pw(int x,int p ){
    int r=1;
    while(p>0) {
        if(p&1) r=r*x;
        x=x*x;
        p>>=1;
    }
    return r;
}
char freq(char a,char b,char c) {
    Vi cnt(2);
    cnt[a-'0']++;
    cnt[b-'0']++;
    cnt[c-'0']++;
    return '0'+(cnt[1]>cnt[0]);
}
string trans(string s) {
    string ns;
    for(int i=0;i<s.size();i+=3) {
        ns+=freq(s[i],s[i+1],s[i+2]);
    }
    return ns;
}
signed main() {
    IOS();
    int n;
    cin>>n;
    vector<string> a(n+1);
    cin>>a[0];
    REP1(i,n) a[i]=trans(a[i-1]);
    vector<Vi> dp(n+1);
    dp[0]=Vi(a[0].size(),1);
    REP1(i,n) {
        dp[i]=Vi(a[i].size(),1);
        REP(j,a[i].size()) {
            int sum=0,mx=0;
            REP(k,3) {
                int id=j*3+k;
                // op(id)ope(dp[i-1].size())
                if(a[i-1][id]==a[i][j]) sum+=dp[i-1][id],chmax(mx,dp[i-1][id]);
            }
            // op(i)op(j)op(sum)ope(mx)
            dp[i][j]=sum-mx;
        }
        // oparr(dp[i])ope(a[i])
    }
    cout<<dp[n][0]<<'\n';
    return 0;
}