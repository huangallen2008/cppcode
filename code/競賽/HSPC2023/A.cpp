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
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
bool isfac(string s) {
    for(char &c:s) if(c=='/') return 1;
    return 0;
}
void opt(pii a) {
    int g=__gcd(a.f,a.s);
    a.f/=g,a.s/=g;
    if(a.s==1) {
        cout<<a.f<<' ';
        return;
    }
    if(a.f>a.s) {
        int x=a.f/a.s,y=a.f%a.s;
        cout<<x<<' ';
        if(y!=0) cout<<y<<'/'<<a.s<<' ';
        return;
    }
    else {
        cout<<a.f<<'/'<<a.s<<' ';
    }
}
signed main() {
    IOS();
    vector<string> in;
    string tt;
    while(cin>>tt) in.pb(tt);
    int it=0;
    pii a,b;
    if(!isfac(in[0])) {
        cout<<"A is a Mixed Fraction.\n";
        stringstream ss;
        ss<<in[1];
        int p,q;
        char c;
        ss>>p>>c>>q;
        p+=q*stoi(in[0]);
        it=2;
        a={p,q};
    }
    else {
        stringstream ss;
        ss<<in[0];
        int p,q;
        char c;
        ss>>p>>c>>q;
        if(p<=q) cout<<"A is a Proper Fraction.\n";
        else cout<<"A is a Improper Fraction.\n";
        it=1;
        a={p,q};
    }
    char sy=in[it++][0];
    if(!isfac(in[it])) {
        cout<<"B is a Mixed Fraction.\n";
        stringstream ss;
        ss<<in[it+1];
        int p,q;
        char c;
        ss>>p>>c>>q;
        p+=q*stoi(in[it]);
        b={p,q};
    }
    else {
        stringstream ss;
        ss<<in[it];
        int p,q;
        char c;
        ss>>p>>c>>q;
        if(p<=q) cout<<"B is a Proper Fraction.\n";
        else cout<<"B is a Improper Fraction.\n";
        b={p,q};
    }
    opt(a);
    cout<<sy<<' ';
    opt(b);
    cout<<'\n';
    if(sy=='+') {
        pii c={a.f*b.s+b.f*a.s,a.s*b.s};
        opt(c);
    }
    else {
        if(sy=='/') swap(b.f,b.s);
        pii c={a.f*b.f,a.s*b.s};
        opt(c);
    }
    cout<<'\n';
    return 0;
}