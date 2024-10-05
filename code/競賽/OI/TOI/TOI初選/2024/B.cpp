#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
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
#define oparr(x) cout<<(#x)<<":";REP(i,(x).size()) cout<<x[i]<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=2e5+5;
const int maxv=1e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}

signed main() {
    IOS();
    int m,n,t,k,ro;
    cin>>n>>m>>t>>k>>ro;
    vector<int> c(t+2);
    c[t+1]=m+1;
    REP1(i,t) cin>>c[i];
    int l=0,r=prev(upper_bound(ALL(c),k))-c.begin(),il=0,ir=k;
    int cnt1=r;
//    ope(cnt1)
    bool okc=(k&1)^1;
    int an=0;
//    if((cnt1&1)==okc) an++;
    while(r<=t) {
        int g1=c[l+1]-il,g2=c[r+1]-ir;
        if((cnt1&1)==okc) {
            an+=min(g1,g2);
        }
        if(g1<g2) {
            il+=g1,ir+=g1;
            l++;
            cnt1--;
        }
        else if(g2<g1) {
            il+=g2,ir+=g2;
            r++;
            cnt1++;
        }
        else {
            il+=g1,ir+=g2;
            l++,r++;
        }
    }
    int cntall=n-k+1;
    int cntan=max(min(ro+k-1,n)-max(ro,k)+1,(int)0);
//    op(min(ro+k-1,n))ope(max(ro,k));
    int oth=cntall-cntan;
    an*=cntan;
    if(k&1) {
        an+=oth*(m-k+1);
    }
//    ope(cntall)ope(cntan)
    cout<<an<<'\n';
    return 0;
}
/*
3 4
2 2 1
2 4

4 5
3 3 3
1 3 4
*/
