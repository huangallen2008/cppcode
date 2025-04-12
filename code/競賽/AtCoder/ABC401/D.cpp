#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("Ofast,unroll-loops")
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
const int mod=1e9;
const int maxn=500+5;
const int maxb=18;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    s='.'+s+'.';
    REP(i,n) {
        if(s[i]=='?'&&(s[i-1]=='o'||s[i+1]=='o')) s[i]='.';
    }
    int st=-1;
    Vpii id;
    REP(i,n+2) {
        if(i<n+1&&s[i]=='.'&&s[i+1]=='?') st=i+1;
        if(i<n+1&&s[i]=='?'&&s[i+1]=='.') {
            id.pb({st,i});
        }
    }
    Vi id;
    int cnto=0;
    for(char c:s) cnto+=c=='o';
    int cnt=0;
    REP(i,SZ(id)) cnt+=id[i].s-id[i].f+2>>1;
    // ope(cnt)
    if(cnt+cnto==k) {
        string an=s;
        REP(i,SZ(id)) {
            if(id[i].s-id[i].f&1) continue;
            for(int j=id[i].f;j<=id[i+1].s;j+=2) {
                an[j]='o';
            }
        }
        string ans;
        REP1(i,n) ans+=an[i];
        cout<<ans<<'\n';
    }else {
        string an=s;
        REP1(i,n) {
            if(an[i]=='?'&&(an[i-1]=='o'||an[i+1]=='o')) an[i]='.';
        }
        string ans;
        REP1(i,n) ans+=an[i];
        cout<<ans<<'\n';
    }
    return 0;
}
