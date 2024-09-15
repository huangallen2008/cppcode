#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define f first 
#define s second 
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define pb push_back
const int maxv=6e6;
vector<int> minp(maxv+1);
vector<int> ip(maxv+1);
const int maxn=4e5+5;
vector<int> prime={0},pp={0};
vector<pair<bool,int>> dp;
const int m=51;
int msu;
void solve() {
    int n;
    cin>>n;
    int psum=pp[n];
    if(n<=m) {
        vector<int> an;
        bool ok=0;
        vector<bool> ans(n+1);
        for(int i=psum>>1;;i--) {
            if(dp[i].f) {
                int t=i;
                while(t>0) {
                    an.pb(dp[t].s);
                    ans[ip[dp[t].s]]=1;
                    t-=dp[t].s;
                }
                ok=1;
                break;
            }
        }
        REP1(i,n) {
            if(ans[i]) cout<<"A";
            else cout<<"B";
        }
        cout<<'\n';
        // for(int&x:an) cout<<x<<' ';cout<<'\n';
        // int tt=0;
        // for(int&x:an) tt+=x;
        // cout<<pp[n]<<' '<<tt<<" "<<pp[n]-tt<<'\n';
    }
    else {
        int a=0,b=0;
        vector<bool> ina(n+1);
        for(int i=n;i>m;i--) {
            if(a>b) {
                b+=prime[i];
            }
            else {
                ina[i]=1;
                a+=prime[i];
            }
        }
        // cout<<"p"<<a+b+pp[m]<<'\n';
        if(a<b) {
            swap(a,b);
            for(int i=m+1;i<=n;i++) ina[i]=ina[i]^1;
        }
        // cout<<a<<' '<<b<<'\n';
        vector<int> an;
        for(int i=m+1;i<=n;i++) if(ina[i])an.pb(prime[i]);
        // for(int &x:an) cout<<x<<' ';cout<<'\n';
        int dif=a-b>>1;
        // for(int dd=0;;dd++) {
        // cout<<pp[m]<<' ';
        int ch=(pp[m]>>1)-dif;
        // cout<<ch<<' '<<pp[m]-ch<<'\n';
            // if(dp[(pp[m]>>1)-dif].f) {
        // assert(dp[(pp[m]>>1)-dif].f);
        int t=(pp[m]>>1)-dif;
        while(t>0) {
            an.pb(dp[t].s);
            ina[ip[dp[t].s]]=1;
            t-=dp[t].s;
        }
            // }
        // }
        REP1(i,n) {
            if(ina[i]) cout<<"A";
            else cout<<"B";
        }
        cout<<'\n';
        // for(int &x:an) cout<<x<<' ';cout<<'\n';
        // int tt=0;
        // for(int &x:an) tt+=x;
        // cout<<pp[n]<<' '<<tt<<" "<<pp[n]-tt<<'\n';
        // cout<<(abs(tt*2-pp[n]))<<'\n';
    }
}
signed main() {
    // int n=50;

    for(int i=2;i<=maxv;i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            ip[i] = prime.size();
            prime.pb(i);
            pp.pb(pp.back()+i);
            // pp[ip[i]] += i;
        }
        for (int j=1;(long long)i * prime[j] <= maxv and prime[j] <= minp[i] and j < prime.size();j++) {
            minp[i*prime[j]] = prime[j];
        }
    }
    // cout << prime.size() << "\n";
    // REP(i,100) cout<<prime[i]<<' ';cout<<'\n';
    // cout<<prime.back()<<'\n';
    // int s=0;
    // REP(i,31) s+=prime[i];
    // cout<<s<<endl;
    msu=0; REP(i,m) msu+=prime[i];
    // cout << msu*m << "\n";
    dp=vector<pair<bool,int>>(msu+1);
    dp[0]={1,0};
    for(int i=1;i<=m;i++) {
        for(int j=msu;j>=prime[i];j--) {
            if((!dp[j].f)&&dp[j-prime[i]].f) {
                dp[j].f=1;
                dp[j].s=prime[i];
            }
        }
    }
    // REP(i,200) cout<<dp[i].s<<' ';cout<<endl;
    // REP1(i,msu) cout<<dp[i].f;cout<<endl;
    // for(int i=msu-100;i<=msu;i++) cout<<dp[i].f;cout<<'\n';
    int T;
    cin>>T;
    while(T--) solve();
    // for(int i=0;i<640;i++) cout<<dp[m][i].f;cout<<endl;
    // for (int i=1;i<=m;i++) {
    //     for (int j=0;j<=20;j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // if(n<=20) {
    //     int sum = 0;
    //     for (int i=0;i<n;i++) {
    //         sum += prime[i];
    //     }
    // }
    return 0;
}