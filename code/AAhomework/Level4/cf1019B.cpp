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
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
const int mod=1e9+7;
const int maxn=21;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
int qu(int u) {
    cout<<"? "<<u<<endl;fflush(stdout);
    int v;cin>>v;
    return v;
}
void ans(int v) {
    cout<<"! "<<v<<endl;fflush(stdout);
    exit(0);
}
signed main() {
    IOS();
    int N;
    cin>>N;
    int n=N/2;
    int a1=qu(1);
    int an=qu(n+1);
    int v0=a1-an,vn=-v0;
    if(abs(v0)%2!=0) {
        ans(-1);
    }
    int l=1,r=n,m;
    while(l<r) {
        m=(l+r)/2;
        int a1=qu(m),a2=qu(n+m);
        int v=a1-a2;
        if(v*vn>=0) r=m;
        else l=m+1;
    }
    ans(l);
    return 0;
}
