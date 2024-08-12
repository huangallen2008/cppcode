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
// const int mod=1e9+7;
// const int maxn=2e5+5;
// const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}


const int N=1<<20;
struct NTT {
    const int mod=998244353;
    const int G=3;
    const int INVG=332748118;
    vector<int> r,c;
    int n1,n2,t,lt;
    int pw(int x,int p) {
        int r=1;
        while(p>0) {
            if(p&1) r*=x,r%=mod;
            x*=x,x%=mod;
            p>>=1;
        }
        return r;
    }
    int inv(int x) {
        return pw(x,mod-2);
    }
    int MA(int a,int b) { int c=a+b;if(c>mod) c-=mod;return c; }
    int MM(int a,int b) { int c=a-b;if(c<0) c+=mod;return c; }
    int MU(int a,int b) { int c=0; if(a<b) swap(a,b); while(b>0) { if(b&1) c=MA(c,a); a=MA(a,a); b>>=1;} return c;}
    void ntt(vector<int> &a,int opt){
        for (int i=0;i<t;i++) if(i<r[i]) swap(a[i],a[r[i]]);
        for (int m=1;m<t;m<<=1){
            int OMG=pw(opt==1?G:INVG,(mod-1)/(m<<1));
            for (int l=0;l<t;l+=m<<1){
                int omg=1;
                for (int k=0;k<m;k++,){
                    int t1=a[l+k],t2=a[l+m+k]*omg%mod;
                    a[l+m+k]=MM(t1-t2);
                    a[l+k]=MA(t1+t2);
                    omg*= OMG,omg %= mod;
                }
            }
        }
    }
    vector<int>& init(vector<int>&a,vector<int>&b){
        int n1=a.size(),n2=b.size();
        t=1,lt=0;
        while(t<n1+n2) t<<=1,lt++;
        while(a.size()<t) a.pb(0);
        while(b.size()<t) b.pb(0);
        r=c=vector<int>(t);
        REP(i,t) r[i]=(r[i>>1]>>1)|((i&1)<<(lt-1));
        ntt(a,1),ntt(b,1);
        for (int i=0;i<t;i++) c[i]=a[i]*b[i]%mod;
        ntt(c,-1);
        int invn=inv(t);
        for(int i=0;i<=n1+n2;i++) c[i]=c[i]*invn%mod;
        return c;
    }
}ntt;
signed main() {
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m);
    REP(i,n) cin>>a[i];
    REP(i,m) cin>>b[i];
    vector<int> c=ntt.init(a,b);
    oparr(c)
    return 0;
}