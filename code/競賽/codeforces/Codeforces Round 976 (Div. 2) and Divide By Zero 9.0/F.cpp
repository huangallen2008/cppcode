#include<bits/stdc++.h>
using namespace std;
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
const int maxn=5;
const int maxv=31700;
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int pw(int x,int p) {
    int r=1;
    while(p>0) {
        if(p&1) r=r*x%mod;
        x=x*x%mod;
        p>>=1;
    }
    return r;
}
int inv(int x) {
    return pw(x,mod-2);
}
Vi prime;
bitset<maxv> isp;
void solve() {

}
signed main() {
    IOS();
    isp.set();
    isp[0]=isp[1]=0;
    for(int i=2;i*i<maxv;i++) {
        if(isp[i]){
            for(int j=i+i;j<maxv;j+=i) isp[j]=0;
        }
    }
<<<<<<< HEAD
    map<Vi,int>mp;
    REP1(i,maxv-1) {
        // cout<<i<<": "; 
            Vi v;
=======
    REP1(i,100) {
        cout<<i<<": "; 
>>>>>>> 961277bad31ba2c70f80a55a07a09c7a4594a887
        REP1(j,i) {
            int t=i;
            if(isp[j]&&t%j==0) {
                int cnt=0;
                while(t%j==0) {
                    t/=j;
                    cnt++;
                }
<<<<<<< HEAD
                v.pb(cnt);
                // cout<<cnt<<", ";
            }
            // else if(isp[j]) cout<<" , ";
        }
        mp[v]++;
        // cout<<'\n';
    }
    for(auto [x,y]:mp) {
       cout<<"{"; for(int t:x) cout<<t<<' ';cout<<"} ";cout<<y<<'\n';
    }
    cout<<"owo"<<endl;
=======
                cout<<cnt<<", ";
            }
            else if(isp[j]) cout<<" , ";
        }
        cout<<'\n';
    }
>>>>>>> 961277bad31ba2c70f80a55a07a09c7a4594a887
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}