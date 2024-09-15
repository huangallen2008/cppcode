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
#define md(x) ((x%(mod)+(mod))%(mod))
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
const int inf=(int)9e18;
const int maxn=1e5+5;
const int mod=1e9+7;//first <=m is >=k
signed main() {
    IOS();
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    REP(i,n) cin>>a[i];
    sort(ALL(a));
    k=(n+1)*n/2-k+1;
    int l=a[0]*2,r=a[n-1]*2,m;
    while(l<r) {
        m=l+(r-l)/2;
        int nk=0;
        REP(i,n) nk+=max((int)0,upper_bound(ALL(a),m-a[i])-a.begin()-i);
        if(nk>=k) r=m;
        else l=m+1;
    }
    if((l%2+2)%2!=0) cout<<l<<"\n2\n";
    else cout<<(l/2)<<"\n1\n";
    return 0;
}
