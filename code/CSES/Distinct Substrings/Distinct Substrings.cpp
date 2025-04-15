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
const int maxv=1000;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int SA(string s) {
    s+='$';
    int n=SZ(s);
    Vi p(n),rk(n);
    REP(i,n) p[i]=i;
    sort(ALL(p),[&](int a,int b) { return s[a]<s[b]; });
    rk[p[0]]=0;
    REP1(i,n-1) rk[p[i]]=rk[p[i-1]]+(s[p[i]]!=s[p[i-1]]);
    auto count_sort=[&]() {
        vector<Vi> cnt(n);
        for(int x:p) cnt[rk[x]].pb(x);
        int it=0;
        REP(i,n) for(int x:cnt[i]) p[it++]=x;
    };
    for(int k=1;k<n;k<<=1) {
        REP(i,n) p[i]=(p[i]-k+n)%n;
        count_sort();
        Vi nrk(n);
        nrk[p[0]]=0;
        REP1(i,n-1) nrk[p[i]]=nrk[p[i-1]]+(rk[p[i]]!=rk[p[i-1]]||rk[(p[i]+k)%n]!=rk[(p[i-1]+k)%n]);
        swap(rk,nrk);
    };
    //lcp
    int k=0;
    Vi lcp(n);
    REP(i,n-1) {
        int j=p[rk[i]-1];
        while(i+k<n-1&&j+k<n-1&&s[i+k]==s[j+k]) k++;
        lcp[i]=k;
        k=max(0ll,k-1);
    }
    int an=0;
    REP(i,n-1) an+=lcp[i];
    return an;
    // p[]  rk[]  lcp[]  
}
signed main() {
    IOS();
    string s;
    cin>>s;
    int n=SZ(s);
    int an=n*(n+1)/2-SA(s);
    cout<<an<<'\n';
    return 0;
}
