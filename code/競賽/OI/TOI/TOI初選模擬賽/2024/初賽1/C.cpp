#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define int long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
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
#define md(x) (((x)%(mod)+(mod))%(mod))
#ifdef LOCAL
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
#else
#define op(x)
#define ope(x)
#define oparr(x)
#define entr
#endif
const int mod=998244353;
const int maxn=2e6+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//struct BIT {
//    int n;
//    vector<int> b;
//    void init(int _n) {
//        n=_n;
//        b=vector<int>(n+1);
//    }
//    void ud(int u,int v) {
//        for(;u<=n;u+=u&-u) b[u]+=v;
//    }
//    int qu(int u) {
//        int r=0;
//        for(;u>0;u-=u&-u) r+=b[u];
//        return r;
//    }
//};
signed main() {
    IOS();
    int n,q;
    cin>>n>>q;
//    BIT bit;
//    bit.init(n+1);
//    vector<int> an(n+1);
//    REP(i,q) {
//        int opt,x;
//        cin>>opt>>x;
//        if(opt==2) {
//            int r=bit.qu(x);
////            op(r)ope(x)
//            bit.ud(x,1);
//            an[x]=max(r+n-x,n*2-i-1)+1;
//        }
//    }
//    REP1(i,n) cout<<an[i]<<'\n';
    vector<int> v,an(n+1);
    REP(i,q) {
        int opt,x;
        cin>>opt>>x;
        if(opt==1) {
            v.pb(x);
        }
        else {
                int id=0;
            REP(j,v.size()) {
            if(v[j]==x) {
                id=j;
                break;
            }
            }
        v.erase(v.begin()+id);
        v.pb(x);
        }
        REP(j,v.size()) an[v[j]]=max(an[v[j]],(int)v.size()-j);
    }
    REP1(i,n) cout<<an[i]<<'\n';
    return 0;
}
