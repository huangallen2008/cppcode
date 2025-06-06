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
int rd(int l,int r) 
{
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() 
{
    IOS();
    int n,m;
    cin>>n>>m;
    Vpii a1,a2;
    REP(i,m) {
        int s,p,g;
        cin>>s>>p>>g;
        if(g==0) a1.pb({p,s});
        else a2.pb({p,s});
    }
    sort(ALL(a1));
    sort(ALL(a2));
    auto chase=[&](pii a,pii b) {//a.f<=b.f
        if(a.f==b.f) return 1;
        if(a.s<=b.s) return 0;//a.s>b.s
        //a.f+a.s*(b.f-a.f)/(a.s-b.s)=(a.s*b.f-a.f*b.s)/(a.s-b.s)
        if(a.s*b.f-a.f*b.s<n*(a.s-b.s)) return 1;
        return 0;
    };
    auto go=[&](Vpii a) ->int{
        Vpii stk;
        for(auto x:a) {
            if(stk.size()==0) stk.pb(x);
            else {
                while(SZ(stk)&&chase(stk.back(),x)) stk.pop_back();
                stk.pb(x);
            }
        }
        // oparr(stk)
        return SZ(stk);
    };
    int an=go(a1)+go(a2);
    cout<<an<<'\n';
    return 0;
}
