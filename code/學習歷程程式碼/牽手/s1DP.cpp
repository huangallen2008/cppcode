#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,popcnt")
// #define int long long
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
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";for(auto &allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=7e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int l,k;
string rc,s;
vector<int> id(26,-1);
unordered_map<string,bool> mp;
string p;
void f() {
    if(p.size()==l) {
        if(mp.find(p)==mp.end()) {
            cout<<p<<'\n';
            exit(0);
        }
        return;
    }
    for(char ch:rc) {
        p+=ch;
        f();
        p.pop_back();
    }
}
template<size_t n> 
bitset<n> operator+(const bitset<n> a,const bitset<n> b) {
    bitset<n> c;
    for(int i=0;i<n-1;i++) {
        c[i+1]=(c[i]&a[i])|(c[i]&b[i])|(a[i]&b[i]);
        c[i]=c[i]^a[i]^b[i];
    } 
    c[n-1]=c[n-1]^a[n-1]^b[n-1];
    return c;
}

signed main() {
    IOS();
    string a,b;
    while(cin>>a>>b) {
        bitset<5> b1(a),b2(b),b3=-b1;
        cout<<(b1).to_ullong()<<' ';
        cout<<(b2).to_ullong()<<' ';
        cout<<(b3).to_ullong()<<' ';
        entr
    }
    return 0;
}