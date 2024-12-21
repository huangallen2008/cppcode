#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
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
#define oparr(x) cout<<(#x)<<":";for(auto allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
template<typename T1,typename T2>
ostream& operator<<(ostream& os,pair<T1,T2> p) { return os<<'{'<<p.f<<','<<p.s<<'}'; }
const int mod=1e9+7;
const int maxn=5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n;
Vi a,pmx,pmn,smx,smn;
Vi cnt;
Vi stk;
int dc(int l,int r) {
    if(l==r) return 0;
    int m=l+r>>1;
    int lan=dc(l,m),ran=dc(m+1,r);
    op(l)op(r)op(m)op(lan)ope(ran)

    smx[m]=smn[m]=a[m];
    for(int i=m-1;i>=l;i--) {
        smx[i]=max(smx[i+1],a[i]);
        smn[i]=min(smn[i+1],a[i]);
    }
    pmx[m+1]=pmn[m+1]=a[m+1];
    for(int i=m+2;i<=r;i++) {
        pmx[i]=max(pmx[i-1],a[i]);
        pmn[i]=min(pmn[i-1],a[i]);
    }
    int an=0;
    for(int i=l;i<=m;i++) {
        //j-i+1==smx[i]-smn[i] ->j=
        int j=smx[i]-smn[i]+i-1;
        if(m<j&&j<=r&&smn[i]<pmn[j]&&pmx[j]<smx[i]) an++;
    }
    for(int i=m+1;i<=r;i++) {
        //i-j+1==pmx[i]-pmn[i]
        int j=i+1-pmx[i]+pmn[i];
        if(l<=j&&j<=m&&pmn[i]<smn[j]&&smx[j]<pmx[i]) an++;
    }
    //smn[i]<pmn[j]
    //smx[i]<pmx[j]
    //pmx[j]-smn[i]=j-i+1 => pmx[j]-j+n=smn[i]-i+1+n
    int lb=m+1,rb=m+1;
    for(int i=m;i>=l;i--) {
        while(rb<=r&&smn[i]<pmn[rb]) cnt[pmx[rb]-rb+n]++,rb++,stk.pb(pmx[rb]-rb+n);
        while(lb<rb&&smx[i]>=pmx[lb]) cnt[pmx[lb]-lb+n]--,lb++;
        an+=cnt[smn[i]-i+1+n];
    }
    while(stk.size()) cnt[stk.back()]=0,stk.pop_back();
    //smn[i]>pmn[j]
    //smx[i]>pmx[j]
    //smx[i]-pmn[j]=j-i+1 => pmn[j]+j+1=smx[i]+i  
    lb=m,rb=m;
    for(int j=m+1;j<=r;j++){
        while(lb>=l&&smn[lb]>pmn[j]) cnt[smx[lb]+lb]++,lb--,stk.pb(smx[lb]+lb);
        while(rb>lb&&smx[rb]<=pmx[j]) cnt[smx[rb]+rb]--,rb--;
        an+=cnt[pmn[j]+j+1];
    }
    ope("ok")
    while(stk.size()) cnt[stk.back()]=0,stk.pop_back();
    return an+lan+ran;
}
signed main() {
    IOS();
    cin>>n;
    cnt=Vi(n<<1|1);
    a=pmx=pmn=smx=smn=Vi(n);
    REP(i,n) {
        int x,y;
        cin>>x>>y,x--,y--;
        a[x]=y;
    }
    int an=dc(0,n-1);
    cout<<an<<'\n';
    return 0;
}