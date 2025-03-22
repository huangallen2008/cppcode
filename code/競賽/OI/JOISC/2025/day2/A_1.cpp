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
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();
    int l,n,T;
    cin>>l>>n>>T;
    T>>=1;
    Vpii a(n);
    REP(i,n) cin>>a[i];
    REP(mask,1<<n) {
        // ope(mask)
        Vpii v1,v2;
        REP(j,n) {
            if(mask>>j&1) v1.pb(a[j]);
            else v2.pb(a[j]);
        }
        sort(ALL(v1),[&](pii a,pii b){ return a.f+a.s<b.f+b.s; } );
        sort(ALL(v2),[&](pii a,pii b){ return a.f-a.s<b.f-b.s; } );
        // sort(ALL(v2));
        Vi p1(SZ(v1)+1),p2(SZ(v2)+1);
        Vi s1(SZ(v1)+1),s2(SZ(v2)+1);
        REP(i,SZ(v1)) p1[i+1]=p1[i]+v1[i].f+v1[i].s-2;
        REP(i,SZ(v1)) s1[i+1]=s1[i]+l-v1[i].f+l-v1[i].s;
        REP(i,SZ(v2)) p2[i+1]=p2[i]+v2[i].f-1+l-v2[i].s;
        REP(i,SZ(v2)) s2[i+1]=s2[i]+l-v2[i].f+v2[i].s-1;
        if(mask==83) {
            oparr(v1)oparr(v2)oparr(p1)oparr(p2)oparr(s1)oparr(s2)
        }
        bool ok1=0,ok2=0;
        REP(i,SZ(p1)) if(p1[i]<=T&&s1.back()-s1[i]<=T) ok1=1;
        REP(i,SZ(p2)) if(p2[i]<=T&&s2.back()-s2[i]<=T) ok2=1;
        if(ok1&&ok2) {
            // oparr(v1)oparr(v2)oparr(p1)oparr(p2)oparr(s1)oparr(s2)
            cout<<"Yes\n";
            return 0;
        }
    }
    cout<<"No\n";
    return 0;
}
/*

7 1:
6 1
3 4

7 7:
6 4
5 5

1 7:
4 5

1 1:
5 1
2 4
*/