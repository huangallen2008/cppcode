#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,sse4,bmi2,popcnt")
// #define int long long
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
// #ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) {cout<<(#x)<<":";for(auto allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;}
#define entr cout<<endl;
// #else
// #define op(x) ;
// #define ope(x) ;
// #define oparr(x) ;
// #define entr ;
// #endif
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
#include "thief.h"
void solve(int n, int m, std::vector<int> U, std::vector<int> V) {
    vector<vector<pipii>> g(n);
    REP(i,m) {
        g[U[i]].pb({V[i],{i,0}});
        g[V[i]].pb({U[i],{i,1}});
    }
    Vi voutt(m);//,vint(m);
    Vi rout(n);//rint(n);
    auto outt=[&](auto outt,int u,int fa)->void{
        for(auto [v,id]:g[u]) {
            if(v==fa) continue;
            auto [ind,dir]=id;
            voutt[ind]=dir;
            outt(outt,v,u);
        }
    };
    // auto intt=[&](auto intt,int u,int fa)->void{
    //     for(auto [v,id]:g[u]) {
    //         if(v==fa) continue;
    //         auto [ind,dir]=id;
    //         vint[ind]=dir^1;
    //         intt(intt,v,u);
    //     }
    // };
    REP(i,n) {
        outt(outt,i,-1);
        rout[i]=query(voutt);
        // intt(intt,i,-1);
        // rint[i]=query(vint);
    }
    int an1=-1;
    auto dout=[&](auto dout,int u,int fa) {
        for(auto [v,id]:g[u]) {
            if(v==fa) continue;
            if(rout[u]!=rout[v]) {
                if(rout[u]) an1=u;
                else an1=v;
                return;
            }
            dout(dout,v,u);
            if(an1!=-1) return;
        }
    };
    dout(dout,0,-1);
    vector<pipii> dfn;
    auto gdfn=[&](auto gdfn,int u,int fa) ->void{
        for(auto [v,w]:g[u]) {
            if(v==fa) continue;
            dfn.pb({v,w});
            gdfn(gdfn,v,u);
        }
    };
    gdfn(gdfn,an1,-1);
    int an2=0;
    {
        int nn=SZ(dfn);
        int lb=0,rb=nn-1,mb;
        while(lb<rb){
            mb=lb+rb>>1;
            Vi vv(m);
            REP(i,nn) vv[dfn[i].s.f]=dfn[i].s.s^(i>mb);
            if(query(vv)) rb=mb;
            else lb=mb+1;
        }
        an2=dfn[lb].f;
    }
    // auto din=[&](auto din,int u,int fa) {
    //     for(auto [v,id]:g[u]) {
    //         if(v==fa) continue;
    //         if(rint[u]!=rint[v]) {
    //             if(rint[u]) an2=u;
    //             else an2=v;
    //             return;
    //         }
    //         din(din,v,u);
    //         if(an2!=-1) return;
    //     }
    // };
    // din(din,0,-1);
    // op(an1)ope(an2)
    answer(an1,an2);
}