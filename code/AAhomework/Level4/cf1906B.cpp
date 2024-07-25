#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define int long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
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
#define md(x) (((x)%(mod)+(mod))%(mod))
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";REP(idd,(x).size()) cout<<x[idd]<<" ";cout<<endl;
#define entr cout<<endl;
const int inf=(1ll<<62);
const int maxn=100+5;
const int mod=1e9+7;
void solve() {
    int n;
    cin>>n;
    int p=0,c1=0,c2=0;
    REP(i,n) {
        char c;
        cin>>c;
        if(c=='1') p^=1;
        if(p==1) c1++;
    }
    p=0;
    REP(i,n) {
        char c;
        cin>>c;
        if(c=='1') p^=1;
        if(p==1) c2++;
    }
    if(c1==c2) cout<<"YES\n";
    else if(c1!=0&&n-c1+1==c2) cout<<"YES\n";
    else cout<<"NO\n";
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
