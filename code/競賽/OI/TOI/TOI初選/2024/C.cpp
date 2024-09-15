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
#define oparr(x) cout<<(#x)<<":";REP(rd,(x).size()) cout<<x[rd]<<" ";cout<<" size="<<(x).size()<<endl;
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
bool so(int a,int b) {
    return a>b;
}
int n,k,e;
bool gre(vector<int>&a,vector<int>&b) {
    REP(i,k) {
        if(a[i]>b[i]) return 1;
        else if(a[i]<b[i]) return 0;
    }
    return 0;
}
signed main() {
    IOS();
    cin>>n>>k>>e;
    vector<int> a(n),s(k);
    REP(i,n) cin>>a[i];
    REP(i,k) cin>>s[i];
    sort(ALL(a));
    sort(ALL(s),so);
    map<int,vector<int>> dp;
    dp[0]=vector<int>(k,0);
    REP(i,k) dp[0][i]=0;
    vector<int> use(e+1,-inf);
    vector<bool> ish(e+1);
    REP(i,n) ish[a[i]]=1;
    REP1(i,e) {
        if(ish[i]) {
            continue;
        }
//        ope(i)
        dp[i]=vector<int>(k,0); dp[i][0]=-inf;
        REP(j,k) {
            if(i<s[j]) continue;
            int id=i-s[j];
            if(ish[id]) continue;
            dp[id][j]++;
            if(gre(dp[id],dp[i])) {
                dp[i]=dp[id];
                use[i]=s[j];
            }
            dp[id][j]--;
        }
    }
    vector<int> an;
    int t=e;
    while(t>0) {
//        ope(t)
        if(use[t]==-inf) {
            cout<<"-1\n";
            return 0;
        }
        an.pb(t);
        t-=use[t];
    }
    reverse(ALL(an));
    cout<<an.size()<<'\n';
    for(int v:an) cout<<v<<' ';
    return 0;
}
/*
3 2 8
1 3 4
4 2

3 2 9
3 4 1
4 2

0 4 61
3 5 23 30
*/
