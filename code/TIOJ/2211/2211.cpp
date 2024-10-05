#include<bits/stdc++.h>
#ifndef LOCAL
#include "lib2211.h"
#endif
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
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
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";for(auto &mken:(x)) cout<<mken<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=5;
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
#ifdef LOCAL
Vi an;
int Init() { 
    int n=100000;
    an=Vi(n+1);
    REP1(i,n) an[i]=i+1;
    an[n-1]=1;an[n]=n;
    // shuffle(an.begin()+1,an.end(),rng);
    // oparr(an)
    return n; 
}
int Query(int a,int b) {
    while(b--) a=an[a];
    return a;
}
void Report(int x) {
    if(an[x]==1) {
        cout<<"AC!\n";
    }
    else cout<<"WA!\n";
}
#endif
int qur(int a,int b) {
    return Query(a,b);
}
signed main() {
    IOS(); 
    int n=Init();
    Vi ret(n+1,-1);
    Vi q;
    // REP(i,n<<1) q[i]=i+1;
    // shuffle(ALL(q),rng);
    int fn1=qur(1,n);
    if(fn1==1) {
        if(n==1) Report(1);
        else Report(qur(1,n-1));
        return 0;
    }
    ret[fn1]=n;
    int sn=sqrt(n);
    REP1(i,sn-1) q.pb(i);
    REP1(i,sn) q.pb(sn*i);
    REP(i,q.size()) {
        int a=q[i];
        int r;
        if(a>n) r=qur(fn1,a-n);
        else r=qur(1,a);
        // op(a)ope(r)
        if(r==1) {
            if(a==1) Report(1);
            else Report(qur(1,a-1));
            return 0;
        }
        if(ret[r]!=-1&&ret[r]!=a) {
            int dif=abs(ret[r]-a);
            if(dif==1) Report(r);
            else Report(qur(1,dif-1));
            return 0;
        }
        ret[r]=a;
    }
    return 0;
}