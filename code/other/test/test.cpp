#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,popcnt")
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
// const int mod=1e9+7;
// const int maxn=2e5+5;
// const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}

const int mod=1004535809;

// const int N=1<<20;
namespace NTT {
    // int MA(int a,int b) { int c=a+b; if(c>=mod) c-=mod; return c; }
    int& MA(int &a,int b) { a+=b; if(a>=mod) a-=mod; return a;}
    // int MM(int a,int b) { int c=a-b; if(c<0) c+=mod; return c; }
    int& MM(int &a,int b) { a-=b; if(a<0) a+=mod; return a; }
    // int MU(int a,int b) { int c=0; if(a<b) swap(a,b); while(b>0) { if(b&1) c=MA(c,a); a=MA(a,a); b>>=1; } return c; }
    int& MU(int &c,int b) { return c=(__int128)c*b%mod; }
    int pw(int x,int p) {
        int r=1;
        while(p>0) {
            if(p&1) MU(r,x);
            MU(x,x);
            // r*=x,r%=mod;
            // x*=x,x%=mod;
            p>>=1;
        }
        return r;
    }
    int inv(int x) {
        return pw(x,mod-2);
    }
    const int G=3;
    const int INVG=inv(G);
    vector<int> r,c,a,b;
    int n1,n2,t,lt;
    void _ntt(vector<int> &a,int opt){
        for(int i=0;i<t;i++) if(i<r[i]) swap(a[i],a[r[i]]);
        for(int m=1;m<t;m<<=1){
            int gn=pw(opt==1?G:INVG,(mod-1)/(m<<1));
            for(int l=0;l<t;l+=m<<1){
                int g=1;
                for(int k=l;k<l+m;k++){
                    int t1=a[k],t2=MU(a[k+m],g);
                    int tt;
                    a[k+m]=MM(tt=t1,t2);
                    a[k]=MA(tt=t1,t2);
                    MU(g,gn);
                    // g*=gn,g%=mod;
                }
            }
        }
    }
    vector<int>& ntt(vector<int>&_a,vector<int>&_b){
        a=_a,b=_b;
        n1=a.size(),n2=b.size();
        t=1,lt=0;
        while(t<n1+n2) t<<=1,lt++;
        while(a.size()<t) a.pb(0);
        while(b.size()<t) b.pb(0);
        r=c=vector<int>(t);
        REP(i,t) r[i]=(r[i>>1]>>1)|((i&1)<<(lt-1));
        _ntt(a,1),_ntt(b,1);
        for (int i=0;i<t;i++) c[i]=MU(a[i],b[i]);
        _ntt(c,-1);
        int invn=inv(t);
        for(int i=0;i<=n1+n2;i++) MU(c[i],invn);
        // while(c.size()&&c.back()==0) c.pop_back();
        return c;
    }
};
const int inf=1000000000;
int pw(int x,int p) 
{
    int r=1;
    while(p>0) {
        if(p&1) r*=x,r%=1000;
        x*=x,x%=1000;
        p>>=1;
    }
    return r;
}
void f(int a=0,int b=0,int c=0,int d=0) {
    op(a)op(b)op(c)op(d)

}
int& pp(int& a,int b) {
    return a=a+b;
}
signed main() {
    IOS();
    int t=1;
    f(pp(t,5),pp(t,4),pp(t,-1));
    ope(t)
    // REP1(i,200) cout<<i<<'\n';
    // cout<<"\\n";
    return 0;
}