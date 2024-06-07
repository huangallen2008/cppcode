#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";
#define entr cout<<endl;
const int inf=(1ll<<62);
const int maxn=2e3+5;
const int maxk=1e5+5;
const int mod=998244353;
struct BIT {
    vector<int> b;
    int n;
    void init(int _n) {
        n=_n;
        b=vector<int>(n+1);
    }
    void ud(int u,int v) {
        u++;
        for(;u<=n;u+=u&-u) b[u]+=v;
    }
    int qu(int u) {
        u++;
        int r=0;
        for(;u>0;u-=u&-u) r+=b[u];
        return r;
    }
    int range_qu(int a,int y) {
        if(a>y) return 0;
        y++;
        return b[y]-b[a];
    }
};
int sum(int n) {
    return n*(n+1)/2;
}
void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> p(n),q(k);
    REP(i,n) cin>>p[i];
    REP(i,k) cin>>q[i];
    BIT bit;
    bit.init(k);
    int pre_an=0;
    REP(i,k) {
        pre_an=(pre_an+bit.range_qu(q[i]+1,k-1))%mod;
        bit.ud(q[i],1);
    }
    pre_an=(pre_an*n)%mod;
    bit.init(n*2);
    int an=pre_an;
    REP(i,n) {
        int t=p[i];
        for(int j=q[i]+1;j<k;j++) {
            t>>=1;
            int ret=bit.range_qu(t+1,(n<<1)-1);
            if(ret<i) an=(an+ret)%mod;
            else {
                an=(an+i*sum(k-(j-q[i])))%mod;
            }
        }
        t=p[i];
        for(int j=q[i]-1;j>=0;j--) {
            t<<=1;
            int ret=bit.range_qu(t+1,(n<<1)-1);
            if(ret>0) an=(an+ret)%mod;
            else {
                an=(an+i*sum(k-(q[i]-j)))%mod;
            }
        }
        t=p[i];
        an=(an+bit.range_qu(t+1,(n<<1)-1))%mod;
        bit.ud(i,p[i]);
    }
    cout<<an<<'\n';
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}
