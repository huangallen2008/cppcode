#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,bmi,popcnt")
#define int long long
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<=(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) (int)((x).size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define Graphw vector<vector<pii>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#define MD(x,M) (((x)%(M)+(M))%(M))
#define ld long double
#define pdd pair<ld,ld>
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define addmod(x,y) x=((x+(y))%mod)
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
// int pw(int x,int p) {
//     int r=1;
//     while(p>0) {
//         if(p&1) {
//             r*=x;
//             r%=mod;
//         }
//         x*=x;
//         x%=mod;
//         p>>=1;
//     }
//     return r;
// }
// int inv(int x) {
//     return pw(x,mod-2);
// }
// vector<int> fac(40),infac(40);
// int C(int n,int m) {
//     return (fac[n]*infac[m]%mod)*infac[n-m]%mod;
// }
// int H(int n,int k) {
//     if(k<0||n<0) return 0;
//     if(n==0) return k==0;
//     return C(n+k-1,k);
// }
// int H1(int n,int k) { return H(n,k-n); }
// int cal(int n,int k,bool is_inc) {//n bit,fir:k
//     int an=0;
//     for(int l=2;l<n;l++) {
//         for(int r=l;r<n;r++) {
//             for(int v=k;v<10;v++) {
//                 an+=H(l-1,is_inc?v-k:v-1-k)*H(n-r+1,v-1);
//             }
//         }
//     }
//     op(n)op(k)op(is_inc)ope(an)
//     return an;
// }
// int cal_down(int n,int k) {//n bit,fir:k,down
//     int an=0;
//     an=H(n,k);
//     op("d")op(n)op(k)ope(an)
//     return an;
// }
// int cal_all(int n) {
//     int an=0;
//     for(int l=2;l<n;l++) {
//         for(int r=l;r<n;r++) {
//             for(int v=1;v<10;v++) {
//                 an+=H(l,v-1)*H(n-r+1,v-1);
//             }
//         }
//     }
//     return an;
// }
vector<int> pw10(20);
int biti(int n,int i) {
    return (n/pw10[i])%10;
}
bool check(int n) {
    vector<int> b(10);
    REP(i,10) b[i]=biti(n,i);
    int mx=0;
    RREP(i,10) if(b[i]){mx=i;break;}
    int lt=0,rt=mx;
    while(lt<n-1&&b[lt+1]>=b[lt]) lt++;
    while(rt>0&&b[rt-1]>=b[rt]) rt--;
    if(lt>=rt&&b[0]!=b[lt]&&b[mx]!=b[rt]) return 1;
    return 0;
}
signed main() {
    IOS();
    // fac[0]=1,infac[0]=1;
    // REP1(i,29) fac[i]=fac[i-1]*i%mod;
    // REP1(i,29) infac[i]=inv(fac[i]);
    // oparr(fac)
    pw10[0]=1;
    REP1(i,18) pw10[i]=pw10[i-1]*10;
    int n;
    cin>>n;
    int cnt=0;
    REP1(i,n) cnt+=check(i);
    cout<<cnt<<'\n';
    // if(n==(int)1e18) n--;

    // vector<int> b(20);
    // REP(i,19) b[i]=biti(n,i);
    // int an=0;
    // bool no0=1;
    // bool is_inc=0;
    // int rcnt=0;
    // RREP(i,18) {
    //     if(no0&&b[i]>0) {
    //         an+=cal_all(i);
    //         no0=0;
    //     }if(!no0) rcnt++;
    //     op(i)op(is_inc)ope(rcnt)
    //     for(int j=0;j<b[i];j++) {
    //         if(is_inc||j>b[i+1])an+=cal_down(i+1,j)-(j>=b[i+1]);
    //         if(j>=b[i+1]&&rcnt>=2) an+=cal(i+1,j,is_inc);
    //     }
    //     if(!no0&&rcnt>1) {
    //         if(b[i]>b[i+1]) is_inc=1;
    //     }
    // }
    // cout<<an<<'\n';
    return 0;
}
