#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,bmi,popcnt")
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
const int maxn=1e4+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
string ord="$NESW";
int toid(char c) {
    if(c=='N') return 1;
    if(c=='E') return 2;
    if(c=='S') return 3;
    return 4;
}
int ton(char c) {
    if(isdigit(c)) return c;
    if(c=='T') return 10;
    if(c=='J') return 11;
    if(c=='Q') return 12;
    if(c=='K') return 13;
    return 0;
}
int fwtn(string fw) {
    if(fw=="C") return 1;
    if(fw=="D") return 2;
    if(fw=="H") return 3;
    if(fw=="S") return 4;
    if(fw=="NT") return 5;
    return 0;
}
string big_c(string c1,string c2) {
    int n1=ton(c1[0]),n2=ton(c2[0]);
    if(n1>n2) return c1;
    if(n1<n2) return c2;
    string fw1=c1.substr(1,c1.size()-1),fw2=c2.substr(1,c2.size()-1);
    int f1=fwton(fw1),f2=fwton(fw2);
    if(f1>f2) return c1;
    if(f1<f2) return c2;
    return c1;
}
void solve() {
    char fir_c;
    cin>>fir_c;
    int fir=toid(fir_c);
    int cons_pass=0;
    string nkc="0";
    while() {
        string s;
        cin>>s;
        if(big_c(nkc,s)==s&&nkc!=s) {
            nkc=s;
        }
        else {
            cout<<"error\n";
            return ;
        }
    }
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}