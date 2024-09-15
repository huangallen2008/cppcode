#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
//#define int long long
#define ll long long
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
    ll n;
    cin>>n;
    vector<int> a(n);
    int maxv=0;
    REP(i,n) {
        cin>>a[i];
        maxv=max(maxv,a[i]);
    }
    ll an=0;
    vector<int> cnt(maxv);
    REP(i,n) {\
        vector<int> pm;
        int ai=a[i];
        for(int j=2;j*j<=ai;j++) {
            if(ai%j==0) {
                pm.pb(j);
                while(ai%j==0) ai/=j;
            }
        }
        if(ai>1) pm.pb(ai);
        int nn=pm.size();
        ll t=0;
        vector<int> d(1<<nn),c1(1<<nn);
        d[0]=1;
        for(int j=1;j<1<<nn;j++) {
            int k2=j&-j;
            int k=j&~k2;
            int l=__lg(k2);
            c1[j]=c1[k]+1;
            d[j]=d[k]*pm[l];
            if(c1[j]&1) t+=cnt[d[j]];
            else t-=cnt[d[j]];
        }
        an+=t;
        for(int j=1;j<1<<nn;j++) cnt[d[j]]++;
    }
    cout<<(n*(n-1)>>1)-an<<'\n';
    return 0;
}

