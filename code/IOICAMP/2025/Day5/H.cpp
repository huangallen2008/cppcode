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
const int inf=1e9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
#define uint uint64_t
const uint B=131;
struct AC {
    vector<uint> pow_p,h;
    void init(string s){
        pow_p=vector<uint>(1,1);
        h=vector<uint>(s.size()+1,0);
        while(pow_p.size()<=s.size()) pow_p.pb(pow_p.back()*B);
        for(int i=0;i<s.size();i++) h[i+1]=(h[i]*B+(uint)s[i]);
    }
    uint gethash(int l,int r) {
        return (h[r+1]-h[l]*pow_p[r-l+1]);
    }
}ac;
signed main() {
    IOS();
    string s;
    cin>>s;
    ac.init(s);
    auto ok=[&](int l,int r) {
        // op(l)ope(r)
        int len=r-l+1>>2;
        //l~l+len-1 , l+len~l+2len-1, l+2len~l+3len-1, l+3len~l+4len-1
        if(ac.gethash(l,l+len-1)-ac.gethash(l+3*len,l+4*len-1)==0&&ac.gethash(l+len,l+2*len-1)-ac.gethash(l+2*len,l+3*len-1)==0) return 1;
        return 0;
    };
    int an=0;
    REP(i,s.size()) {
        REP(j,i+1) {
            if((i-j+1)%4==0&&ok(j,i)) an++;
        }
    }
    cout<<an<<'\n';
    return 0;
}