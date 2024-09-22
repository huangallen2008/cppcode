#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2")
// #pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
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
#define Vi vector<int>
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";for(auto &mken:(x)) cout<<mken<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=8e7;
const int sn=sqrt(maxn);
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
bool pr1[maxn],pr2[maxn];
bitset<maxn> p1,p2;
void f1() {
    auto st=clock();
    pr1[0]=pr1[1]=1;
    for(int i=2;i<maxn;i++) {
        if(!pr1[i]) {
            // for(int j=(maxn-1)/i,k=j*i;k>=i;j--,k-=i) {
            //     if(!pr1[j]) {
            //         pr1[k]=1;
            //     }
            // }
            for(int k=i*i;k<maxn;k+=i) {
                // if(!pr1[j]) {
                    pr1[k]=1;
                // }
            }
        }
    }
    cout<<fixed<<setprecision(3)<<(ld)(clock()-st)/CLOCKS_PER_SEC<<'\n';
}
void f2() {
    auto st=clock();
    pr2[0]=pr2[1]=1;
    for(int i=2;i<maxn;i++) {
        if(!pr2[i]) {
            for(int j=i*i;j<=maxn;j++) {
                // if(!pr2[j]) {
                    pr2[j]=1;
                // }
            }
        }
    }
    cout<<fixed<<setprecision(3)<<(ld)(clock()-st)/CLOCKS_PER_SEC<<'\n';
}
void f3() {
    auto st=clock();
    p1[0]=p1[1]=1;
    for(int i=2;i<maxn;i++) {
        if(!p1[i]) {
            for(int j=(maxn-1)/i,k=j*i;k>=i;j--,k-=i) {
                if(!p1[j]) {
                    p1[k]=1;
                }
            }
        }
    }
    cout<<fixed<<setprecision(3)<<(ld)(clock()-st)/CLOCKS_PER_SEC<<'\n';
}
void f4() {
    auto st=clock();
    p2[0]=p2[1]=1;
    for(int i=2;i<maxn;i++) {
        if(!p2[i]) {
            for(int j=i*i;j<=maxn;j++) {
                // if(!pr2[j]) {
                    p2[j]=1;
                // }
            }
        }
    }
    cout<<fixed<<setprecision(3)<<(ld)(clock()-st)/CLOCKS_PER_SEC<<'\n';
}
signed main() {
    IOS(); 
    op(1)f1();
    op(2)f2();
    op(3)f3();
    op(4)f4();
    return 0;
}