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
#define double long double
const int inf=(1ll<<62);
const int maxn=100+5;
const int maxV=1e9+5;
const int mod=1e9+7;
int n;
double get_an(vector<double> &t) {
    vector<double> dp(n+1,-inf);
    dp[0]=0;
    dp[1]=max(t[1],(double)0);
    for(int i=2;i<=n;i++) {
        dp[i]=max(dp[i-1]+t[i],dp[i-2]+t[i-1]);
    }
    return dp[n];
}
int get_an(vector<int> &t) {
    vector<int> dp(n+1,-inf);
    dp[0]=0;
    dp[1]=max(t[1],(int)0);
    for(int i=2;i<=n;i++) {
        dp[i]=max(dp[i-1]+t[i],dp[i-2]+t[i-1]);
    }
    return dp[n];
}
signed main() {
    IOS();
    cin>>n;
    vector<int> a(n+1);
    REP1(i,n) cin>>a[i];
    double a_l=0,a_r=maxV,a_m;
    int a_bs_time=100;
    while(a_bs_time--) {
        a_m=(a_l+a_r)/2;
        vector<double> t(n+1);
        REP1(i,n) t[i]=(double)a[i]-a_m;
        double res=get_an(t);
        if(res>=0) a_l=a_m;
        else a_r=a_m;
    }
    int m_l=1,m_r=maxV,m_m;
    while(m_l<m_r) {
        m_m=(m_l+m_r)/2;
        vector<int> t(n+1);
        REP1(i,n) t[i]=(a[i]>m_m?1:-1);
        int res=get_an(t);
        if(res<=0) m_r=m_m;
        else m_l=m_m+1;
    }
    cout<<fixed<<setprecision(7)<<a_l<<'\n';
    cout<<m_l<<'\n';
    return 0;
}
