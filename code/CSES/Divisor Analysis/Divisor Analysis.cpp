#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#define int long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#define MD(x,M) (((x)%(M)+(M))%(M))
#define ld long double
#define pdd pair<ld,ld>
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";REP(rd,(x).size()) cout<<x[rd]<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=2e5+5;
const int maxv=1e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int pw(int x,int p) {
    int r=1;
    while(p>0) {
        if(p&1) {
            r*=x;
            r%=mod;
        }
        x*=x;
        x%=mod;
        p>>=1;
    }
    return r;
}
int inv(int x) {
    return pw(x,mod-2);
}
int sm(int x) {
    return (x*(x+1)>>1);
}
signed main() {
    IOS();
    int n;
    cin>>n;
    int an1=1,an2=1,an3=1,an1t=1;
    REP(i,n) {
        int x,k;
        cin>>x>>k;
        an1=md(an1*(k+1));
        an3=md(pw(an3,k+1)*pw(pw(x,sm(k)),an1t));
        an1t=(an1t*(k+1))%(mod-1);
        an2=md(an2*md((pw(x,k+1)-1)*inv(x-1)));
    }
    cout<<an1<<' '<<an2<<' '<<an3<<'\n';
    return 0;
}

