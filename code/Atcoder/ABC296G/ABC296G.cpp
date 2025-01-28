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
struct po {
    int x,y;
    po operator+(po b) { return {x+b.x,y+b.y}; }
    po operator-(po b) { return {x-b.x,y-b.y}; }
};
istream& operator>>(istream& os,po &p) { return os>>p.x>>p.y; }
int sig(int x) { return x<0?-1:(x>0?1:0); }
int cro(po a,po b) { return a.x*b.y-a.y*b.x; }
int dot(po a,po b) { return a.x*b.x+a.y*b.y; }
bool in(po a,po b,po c) { return sig(cro(a,c))*sig(cro(b,c))<=0; }
bool onl(po a,po b,po c) { return dot(b-a,c-a)>=0&&dot(a-b,c-b)>=0&&cro(b-a,c-a)==0; }
signed main() {
    IOS();
    int n;
    cin>>n;
    vector<po> a(n);
    REP(i,n) cin>>a[i];
    int k;
    cin>>k;
    REP(i,k) {
        po x;
        cin>>x;
        if(onl(a[0],a[1],x)||onl(a[0],a[n-1],x)) {
            cout<<"ON\n";
            continue;
        }
        int l=2,r=n,m;
        while(l<r) {
            m=l+r>>1;
            if(in(a[1]-a[0],a[m]-a[0],x-a[0])) r=m;
            else l=m+1;
        }
        if(l==n) {
            cout<<"OUT\n";
            continue;
        }
        // op(a[l-1].x)op(a[l-1].y)op(a[l].x)ope(a[l].y)
        int rr=(cro(a[l]-a[l-1],x-a[l-1]));
        // op(i)op(l)ope(rr)
        if(rr>0) cout<<"IN\n";
        else if(rr==0) cout<<"ON\n";
        else cout<<"OUT\n";
    }
    return 0;
}