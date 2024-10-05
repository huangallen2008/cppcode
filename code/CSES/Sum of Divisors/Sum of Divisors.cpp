#include<bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3")
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,(n)+1)
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
const int maxn=1e6+5;
const int mod=1e9+7;
int pw(int x,int p) {
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
int inv(int x) {
    return pw(x,mod-2);
}
int sum(int l,int r) {
    return (((((l+r)%mod)*((r-l+1)%mod))%mod)*inv(2))%mod;
}
signed main() {
    IOS();
    int n;
    cin>>n;
    int mn=n;
    int an=0;
    for(int i=1;i*i<=n;i++) {
        an=(an+i*sum((int)ceil((double)(n-i)/(i+1))+1,(int)ceil((double)(n-i+1)/i)))%mod;
//        op(an)ope(i)
        mn=min(mn,(int)ceil((double)(n-i)/(i+1)));
    }
//    op(mn)ope(an)
    REP1(i,mn) an=(an+i*(int)(n/i))%mod;
    cout<<an<<'\n';
    return 0;
}
/*

973297711765
*/
