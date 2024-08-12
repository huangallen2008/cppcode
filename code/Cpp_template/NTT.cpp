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


const int N=1<<20;
struct NTT {
    const int MOD=998244353;
    const int G=3;
    const int INVG=332748118;
    vector<int> r,c;
    int n,m,t,lt;
    int pw(int x,int p) {
        int r=1;
        while(p>0) {
            if(p&1) r*=x,r%=mod;
            x*=x,x%=mod;
            p>>=1;
        }
        return r;
    }
    void ntt(vector<int> &A,int opt){
        for (int i = 0;i < t;i ++)
        if (i < r[i]) swap(A[i],A[r[i]]);
        for (int mid = 1;mid < t;mid <<= 1){
            int OMG = pw(opt == 1 ? G : INVG,(MOD - 1) / (mid << 1));
            for (int R = mid << 1,l = 0;l < t;l += R){
                int omg = 1;
                for (int k = 0;k < mid;k ++,(omg *= OMG) %= MOD){
                    int tmp1 = A[l + k],tmp2 = A[l + mid + k] * omg % MOD;
                    A[l + mid + k] = (tmp1 - tmp2 + MOD) % MOD;
                    A[l + k] =(tmp1 + tmp2) % MOD;
                }
            }
        }
    }
    void init(vector<int>&a,vector<int>&b){
        n=a.size(),m=b.size();
        t=0,lt=0;
        ope("ok")
        while(t<=n+m) t<<=1,lt++;
        r=vector<int>(t);
        c=vector<int>(t);
        REP(i,t) r[i]=(r[i>>1]>>1)|((i&1)<<(lt-1));
        ntt(a,1);
        ntt(b,1);
        ope("ok")
        for (int i = 0;i < t;i ++) c[i]=(a[i] *= b[i]) %= MOD;
        ntt(a,-1);
        int invn = pw(t,MOD - 2);
        for (int i = 0;i <= n + m;i ++)
        c[i]=(c[i] * invn) % MOD;
    }
    vector<int>& getan() {return c;}
}ntt;
signed main() {
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m);
    REP(i,n) cin>>a[i];
    REP(i,m) cin>>b[i];
    ntt.init(a,b);
    vector<int> c=ntt.getan();
    oparr(c)
    return 0;
}