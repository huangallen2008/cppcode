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
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<endl;
#define entr cout<<endl;
const int inf=(1ll<<62);
const int maxn=1e5+5;
const int mod=1e9+7;
vector<int> a,an1,an2;
vector<bool> y;
void out(int l,int r) {
    for(int i=l;i<=r;i++) {
        an1.pb(a[i]);
    }
}
void out2(int l,int r) {
    for(int i=l;i<=r;i++) {
        an2.pb(a[i]);
    }
}
signed main() {
    IOS();
    int n;
    cin>>n;
    int n2=(n<<1);
    a=vector<int>(n2|1);
    REP1(i,n2) cin>>a[i];
    vector<bool> vis(n2|1);
    int mx=n2,l=n2+1;
    vector<int> d,id;
    RREP1(i,n2) {
        if(a[i]!=mx) {
            vis[a[i]]=1;
        }
        else {
            id.pb(i);
            d.pb(l-i);
            l=i;
            vis[a[i]]=1;
            while(mx>=0&&vis[mx]) mx--;
        }
    }
//    oparr(d)oparr(id)
    int k=d.size();
    y=vector<bool>(k);
    vector<bool> dp(n+1);
    vector<int> use(n+1,-1);
    dp[0]=1;
    REP(i,k) {
        RREP(j,n+1) {
            if(dp[j]) continue;
            if(j>=d[i]) {
                if(dp[j-d[i]]) {
                    dp[j]=1;
                    use[j]=i;
                }
            }
        }
    }
//    oparr(use)
    if(!dp[n]) cout<<"-1\n";
    else {
        int ni=use[n],nn=n;
        while(ni>=0) {
            y[ni]=1;
            out(id[ni],id[ni]+d[ni]-1);
            nn-=d[ni];
            ni=use[nn];
//            ope(ni)
        }
        RREP(i,k) if(!y[i]) out2(id[i],id[i]+d[i]-1);
        REP(i,n) cout<<an1[i]<<' ';cout<<'\n';
        REP(i,n) cout<<an2[i]<<' ';cout<<'\n';
    }
    return 0;
}
