#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
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
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS(); 
    int n,x;
    cin>>n>>x;
    Vi a(n);
    REP(i,n) cin>>a[i];
    sort(ALL(a));
    auto suf_mnc=[&](int u,int bas=0) {
        int l=u-1,r=n-1,m;
        while(l<r) {//last t : bas+n-1-t>=a[t]
            m=l+r+1>>1;
            if(bas+n-1-m>=a[m]) l=m;
            else r=m-1;
        }
        return bas+n-1-l;
    };
    ope("ok")
    Vi b(n+1);
    b[0]=suf_mnc(0,-1);
    b[1]=suf_mnc(1);
    int na=0;
    REP1(i,n-1) {
        //a[i]/i>na/(i-1)
        if(a[i]*(i)>na*(i+1)) na++;
        b[i+1]=suf_mnc(i+1,na);
    }
    if(x<b[0]) {
        RREP(i,n) cout<<a[i]<<' ';
        cout<<'\n';
    }
    else if(x>b.back()) {
        REP(i,n) cout<<a[i]<<' ';
        cout<<'\n';
    }
    else {
        REP(i,n) {
            if(b[i]==x) {
                REP(j,i) cout<<a[j]<<' ';
                for(int j=n-1;j>=i;j++) cout<<a[j]<<' ';
                cout<<'\n';
                break;
            }
        }
    }
    oparr(b)
    return 0;
}