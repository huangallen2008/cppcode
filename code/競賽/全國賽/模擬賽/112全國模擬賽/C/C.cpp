#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,(n)+1)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
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
#define md(x) (x%mod+mod)%mod
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
const int inf=(1ll<<62);
const int maxn=2e3+5;
const int mod=1e9+7;
int pw(int x,int p,int mod) {
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
int ti(int n,int mod) {
    int l=1,r=n,m;
    while(l<r) {
        m=(l+r+1)/2;
        if(m*(m+1)/2-1<n) l=m;
        else r=m-1;
    }
    return pw(2,max(n-l*(l+1)/2-1,(int)0),mod);
}
struct BIT {
    vector<int> b;
    int n,le;
    void init(int _n) {
        n=_n;
        le=__lg(n);
        b=vector<int>(n+1);
    }
    void ud(int u,int v) {
        for(;u<=n;u+=u&-u) b[u]+=v;
    }
    int kth(int k) {
        int r=0,c=0;
        RREP(i,le+1) {
            if(r+(1<<i)>n) continue;
            if(b[r+(1<<i)]<k) {
                k-=b[r+(1<<i)];
                r+=(1<<i);
            }
        }
        return r+1;
    }
    int psum(int u) {
        int r=0;
        for(;u>0;u-=u&-u) r+=b[u];
        return r;
    }
};
void solve() {
    int n;
    cin>>n;
    BIT bit;
    bit.init(n);
    REP1(i,n) bit.ud(i,1);
    int k=2;
    REP1(i,n-1) {
        int id=bit.kth(k);
        cout<<id<<' ';
        bit.ud(id,-1);
//            op(i)op(k)cout<<"a:";REP1(i,n) cout<<bit.psum(i)<<" ";cout<<endl;
        k+=ti(i,n-i)-1;
        k=((k-1)%(n-i)+n-i)%(n-i)+1;
    }
    cout<<"\n";
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
