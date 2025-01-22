#include "lib0906.h"
#include <bits/stdc++.h>
using namespace std;
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
#define Vi vector<int>
#define Vpii vector<pii>
#ifdef LOCAL
#include"grader.cpp"
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
const int maxv=1e5+5;
const int inf=1e9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
namespace {
    // int n;
}
int qur(int u,Vi s) {
    for(auto &x:s) x++;
    u++;
    // op(u)oparr(s)
    int rr=query(u,s);
    // ope(rr)
    return rr;
}

vector<pair<int, int>> treeguessr(int n) {
    // ::n = n;
    vector<pair<int, int>> e;
    Graph g(n);
    Vi per(n);
    REP(i,n) per[i]=i;
    shuffle(ALL(per),rng);
    Vi ok(n);
    REP(i,n) {
        Vi vv;
        REP(j,n) if(!ok[j]&&per[i]!=j) vv.pb(j);
        if(vv.size()==0) continue;
        int st=0;
        while(1) {
            int l=st,r=vv.size()-1,m;
            Vi tv;
            for(int j=st;j<=r;j++) tv.pb(vv[j]);
            if(tv.size()==0||qur(per[i],tv)!=1) break;
            while(l<r) {
                m=l+(r-l)/3;
                Vi rv;
                for(int j=st;j<=m;j++) rv.pb(vv[j]);
                int ret=qur(per[i],rv);
                // ope(ret)
                if(ret>1) l=m+1;
                else r=m;
            }
            g[per[i]].pb(vv[l]);
            g[vv[l]].pb(per[i]);
            e.pb({per[i],vv[l]});
            st=l+1;
        }
        ok[per[i]]=1;
    }
    // oparr(e)
    for(auto &[x,y]:e)x++,y++; return e;
}