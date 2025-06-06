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
struct mystk {
    Vi a,stk;
    void push(int x) {
        a.pb(x);
        stk.pb(SZ(stk)?x|stk.back():x);
    }
    int pop() { 
        int val=a.back();
        a.pop_back();
        stk.pop_back();
        return val;
    }
    int orv() { return SZ(stk)?stk.back():0; }
    int size() { return SZ(a); }
};
struct myq {
    mystk s1,s2;
    void push(int x) {
        s1.push(x);
    }
    void pop() {
        if(SZ(s2)) s2.pop();
        else {
            while(SZ(s1)) s2.push(s1.pop());
            s2.pop();
        }
    }
    int size() { return SZ(s1)+SZ(s2); }
    int orv() { return size()?s1.orv()|s2.orv():0; }
};
signed main() {
    IOS();
    int n,k;
    cin>>n>>k;
    int x0,a0,b0,c0;
    cin>>x0>>a0>>b0>>c0;
    Vi a(n);
    a[0]=x0;
    REP1(i,n-1) a[i]=(a0*a[i-1]+b0)%c0;
    myq q;
    REP(i,k) q.push(a[i]);
    int an=q.orv();
    for(int i=k;i<n;i++) {
        q.push(a[i]);
        q.pop();
        an^=q.orv();
    }
    cout<<an<<'\n';
    return 0;
}
