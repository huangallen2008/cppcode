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
const int mod=1e9+7;
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
bool so(int a,int b) {
    return a>b;
}
bool so_pii(pii a,pii b) {
    return a.f>b.f;
}
signed main() {
    IOS();
    int n;
    cin>>n;
    vector<int> s(n);
    vector<pii> a(n);
    REP(i,n) cin>>s[i];
    REP(i,n) cin>>a[i].f;
    REP(i,n) cin>>a[i].s;
    // {
    //     int an=0;
    //     REP(i1,n) {
    //         REP(i2,i1) {
    //             REP(i3,i2) {
    //                 int x=a[i1].s,y=a[i2].s,z=a[i3].s;
    //                 int sum=a[i1].f+a[i2].f+a[i3].f+s[x-1];
    //                 if(x!=y) sum+=s[y-1];
    //                 if(z!=x&&z!=y) sum+=s[z-1];
    //                 if(sum==19) {
    //                     op(i1)op(i2)ope(i3)
    //                 }
    //                 an=max(an,sum);
    //             }
    //         }
    //     }
    //     cout<<an<<'\n';
    // }
    vector<vector<int>> l(n);
    REP(i,n) {
        l[a[i].s-1].pb(a[i].f);
    }
    REP(i,n) sort(ALL(l[i]),so);
    vector<pii> v1,v2;
    int an3=0;
    REP(i,n) {
        if(l[i].size()>=1) v1.pb({l[i][0]+s[i],i});
        if(l[i].size()>=2) v2.pb({l[i][0]+l[i][1]+s[i],i});
        if(l[i].size()>=3) an3=max(an3,l[i][0]+l[i][1]+l[i][2]+s[i]);
    }
    sort(ALL(v1),so_pii);
    sort(ALL(v2),so_pii);
    int an1=0;
    if(v1.size()>=3) an1=v1[0].f+v1[1].f+v1[2].f;
    int an2=0;
    if(v1.size()&&v2.size()) {
        // if(v1[0].s==v2[0].s) {
        //     if(v1.size()>=2) an2=max(an2,v1[1].f+v2[0].f);
        //     if(v2.size()>=2) an2=max(an2,v2[1].f+v1[0].f);
        // }
        // else 
        an2=v1[0].f+v2[0].f;
    }
    int an=max(an1,max(an2,an3));
    cout<<an<<'\n';
    return 0;
}