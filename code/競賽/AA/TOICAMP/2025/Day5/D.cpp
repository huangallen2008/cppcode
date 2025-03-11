#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,sse4,bmi2,popcnt")
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
#define Vpii vector<pii>
#ifdef LOCAL
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
const int maxb=64;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct BIT {
    int n;
    Vi b;
    void init(int _n) {
        n=_n;
        b=Vi(n+1);
    }
    void ud(int u,int v) {
        for(;u<=n;u+=u&-u) b[u]+=v;
    }
    int pre(int u) {
        int r=0;
        for(;u>0;u-=u&-u) r+=b[u];
        return r;
    }
    int qu(int l,int r) {  
        return pre(r)-pre(l-1);
    }
    int bs(int k) {
        int u=0;
        for(int i=__lg(n);i>=0;i--) {
            if(u+(1<<i)>n) continue;
            // op(i)ope(b[u+(1<<i)])
            if(k>=b[u+(1<<i)]) {
                u+=1<<i;
                k-=b[u];
            }
        }
        return u;
    }
}c1,c2,v1,v2;
signed main() {
    IOS();
    int n,q;
    cin>>n>>q;
    Vi a(n+1);
    REP1(i,n) cin>>a[i];
    c1.init(n);
    c2.init(n);
    v1.init(n);
    v2.init(n);
    REP1(i,n) {
        if(a[i]==1) c1.ud(i,1),v1.ud(i,i);
        else c2.ud(i,1),v2.ud(i,i);
    }
    REP(i,q) {
        int opt;
        cin>>opt;
        if(opt==1) {
            int u;
            cin>>u;
            if(a[u]==1) {
                c1.ud(u,-1),v1.ud(u,-u);
                c2.ud(u,1),v2.ud(u,u);
            }else {
                c1.ud(u,1),v1.ud(u,u);
                c2.ud(u,-1),v2.ud(u,-u);
            }
            a[u]=3-a[u];
        }else {
            int x;
            cin>>x;
            int ca2=c2.qu(1,n);
            int ca1=c1.qu(1,n);
            int sum=ca2*2+ca1;
            if((sum&1)||x*2<(sum>>1)||(n-x)*2<(sum>>1)) {
                cout<<"-1\n";
                continue;
            }
            int glc2=ca2-x*2+n>>1,grc2=ca2-glc2;
            int glc1=x-glc2,grc1=n-x-grc2;
            int lc1=c1.qu(1,x);
            int lc2=c2.qu(1,x);
            if(lc2>glc2) {
                int rid=c1.bs(lc1+lc2-glc2);
                int lid=c2.bs(glc2)+1;
                int rac=c2.qu(lid,rid);
                int an=(x*2+rac+1)*rac/2-v2.qu(lid,rid);
                cout<<an<<'\n';
            }else {
                int rid=c2.bs(lc2+lc1-glc1);
                int lid=c1.bs(glc1)+1;
                int rac=c1.qu(lid,rid);
                int an=(x*2+rac+1)*rac/2-v1.qu(lid,rid);
                // op(glc1)op(grc1)op(glc2)op(grc2)op(lc1)op(lc2)op(rid)op(lid)op(rac)ope(an)
                cout<<an<<'\n';
            }
        }
    }
    return 0;
}