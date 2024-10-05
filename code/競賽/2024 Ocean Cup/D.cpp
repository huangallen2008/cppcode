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
#define oparr(x) cout<<(#x)<<":";REP(allen,(x).size()) cout<<x[allen]<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=998244353;
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
ld cal_A(ld a,ld b,ld c) {
    ld s=(ld)(a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}
// bool check(int a,int b,int c) {
//     return a+b>=c&&a+c>=b&&c+b>=a;
// }

vector<int> a;
int S=0;
int n;
ld an=inf;
bool check(int u) {
    bitset<250005> b;b.set(0);
    bool ok=0;
    REP(i,n) {
        if(i==u) continue;
        b|=b<<a[i];
    }
    int sum=S-a[u];
    for(int dif=0;dif*2+(sum&1)<=a[u];dif++) {
        int x1=sum/2-dif,x2=(sum+1)/2+dif;
        if(sum&1) {
            if(b[(sum/2)-dif]&&b[(sum+1)/2+dif]) {
                an=min(an,cal_A(a[u],x1,x2)),ok=1;
                // op(an)op(x1)op(x2)ope(cal_A(a[u],x1,x2))
            }
        }
        else {
            if(b[sum/2-dif]&&b[sum/2+dif]) {
                an=min(an,cal_A(a[u],x1,x2)),ok=1;
                // op(x1)op(x2)ope(cal_A(a[u],x1,x2))
            }
        }
    }
    // op(u)ope(ok)ope(an)entr
    return ok;
}
signed main() {
    IOS();
    cin>>n;
    a=vector<int>(n);
    REP(i,n) cin>>a[i];
    REP(i,n) S+=a[i];
    sort(ALL(a));
    if(S-a.back()<a.back()) {
        cout<<"-1\n";
        return 0;
    }
    int l=0,r=n-1,m;
    while(l<r) {
        m=l+r>>1;
        if(check(m)) r=m;
        else l=m+1;
    }
    check(l);
    if(an==inf) cout<<"-1\n";
    else cout<<fixed<<setprecision(15)<<an<<'\n';
    return 0;
}