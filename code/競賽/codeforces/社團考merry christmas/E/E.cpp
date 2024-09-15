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
#ifdef local
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int inf=(1ll<<62);
const int maxn=1e5+5;
const int mod=1e9+7;
bool isa(int n) {
    int t=sqrt(n);
    return t*t==n;
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        int cnt=0;
        for(int i=0;i*i<=n;i++) {
            if(isa(n-i*i)) {
                cnt++;
                if(i!=0) cnt++;
                if(n-i*i!=0) cnt++;
                if(i!=0&&n-i*i!=0) cnt++;
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}
