#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,popcnt")
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
#define MD(x,M) (((x)%(M)+(M))%(M))
#define ld long double
#define pdd pair<ld,ld>
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
const int maxn=3e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n,k,mx;
bool check(int r) {
    int now=1,cnt=0;
    while(now<=n) {
        cout<<"? "<<now<<" "<<r*mx<<"\n";cout.flush();
        int ret;
        cin>>ret;
        if(ret==n+1) return 0;
        else now=ret+1,cnt++;
        if(cnt>k) return 0;
    }
    if(cnt==k) return 1;
    return 0;
}
void solve() {
    cin>>n>>k;
    RREP1(i,n) {
        cout<<"? 1 "<<i*n<<'\n';cout.flush();
        int ret;
        cin>>ret;
        if(ret!=n+1) {
            mx=i;
            break;
        }
    }
    if(k==1) {
        cout<<"! "<<mx*n<<'\n';cout.flush();
        int ret;
        cin>>ret;if(ret==-1) exit(0);
        return;
    }
    for(int i=n/k;i>0;i--) {
        if(check(i)) {
            cout<<"! "<<i*mx<<'\n';cout.flush();
            int ret;cin>>ret;if(ret==-1) exit(0);
            return;
        }
    }
    cout<<"! -1\n";cout.flush();
    int ret;cin>>ret;if(ret==-1) exit(0);
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}