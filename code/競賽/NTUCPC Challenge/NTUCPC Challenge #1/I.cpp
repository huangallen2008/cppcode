#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O0,unroll-loops,fast-math")
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
pii mc(int x,int y,int k) {
    bool inv=x<y;
    if(inv) swap(x,y);
    if(x==1) return {k,0};
    int t=x/y,z=x-t*y;
    pii ret=mc(y,z,k);
    ret={ret.s,ret.f-ret.s*t};
    if(inv) swap(ret.s,ret.f);
    // if(!inv){op(x)op(y)op(ret.f)op(ret.s)op(ret.f*x+ret.s*y)ope(k)}
    // else{op(x)op(y)op(ret.f)op(ret.s)op(ret.f*y+ret.s*x)ope(k)}
    return ret;
}
void solve() {
    int n,m,a,b,k;
    cin>>n>>m>>a>>b>>k;
    if(a*n+b*m<k) {
        cout<<n+m<<'\n';
        return;
    }
    if(a<b) swap(a,b),swap(n,m);
    int gcd=__gcd(a,b);
    bool ok=1;
    pii ret;
    if(k%gcd==0) {
        a/=gcd,b/=gcd,k/=gcd;
        ret=mc(a,b,k);
        if(ret.f<0) {
            int t=(b-1-ret.f)/b;
            ret.f+=b*t,ret.s-=a*t;
            if(ret.s<0) {
                ok=0;
            }
        }
        else if(ret.s<0){
            int t=(a-1-ret.s)/a;
            ret.s+=a*t,ret.f-=b*t;
            if(ret.f<0) {
                ok=0;
            }
        }
    }
    else ok=0;
    if(!ok) {
        cout<<n+m<<'\n';
        return;
    }
    pii amn,bmn;
    {
        int t=(ret.f)/b;
        amn={ret.f-b*t,ret.s+a*t};
    }
    {
        int t=ret.s/a;
        bmn={ret.f+b*t,ret.s-a*t};
    }
    // op(amn.f)op(amn.s)op(bmn.f)op(bmn.s)entr
    int l=0,r=(n*a+m*b)/k,mid;
    while(l<r) {
        mid=l+r+1>>1;
        pii now={amn.f*mid,amn.s*mid};
        if(now.f>n) {
            r=mid-1;
            continue;
        }
        if(now.s<=m) {
            l=mid;
            continue;
        }
        // op(now.f)op(now.s)
        int t=(now.s-m+a-1)/a;
        now={now.f+t*b,now.s-t*a};
        assert(now.s<=m);
        // op(now.f)ope(now.s)
        if(now.f<=n&&now.s>=bmn.s*mid) {
            l=mid;
        }
        else r=mid-1;
    }
    pii now={amn.f*l,amn.s*l};
    if(now.s>m) {
        int t=(now.s-m+a-1)/a;
        now={now.f+t*b,now.s-t*a};
    }
    int an=n+m-now.f-now.s;
    cout<<an<<'\n';
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}