#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
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
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
bool qur(string s) {
    cout<<"? "<<s<<'\n';
    cout.flush();
    int ret;
    cin>>ret;
    return ret;
}
void ans(string s) {
    cout<<"! "<<s<<'\n';
    cout.flush();
}
void solve() {
    int n;
    cin>>n;
    if(n==1) {
        bool i0=qur("0");
        if(i0) ans("0");
        else ans("1");
        return;
    }
    bool i1=qur("01");
    if(!i1) {
        string s="1";
        int c1=n;
        REP1(i,n) {
            bool ok=qur(s);
            if(!ok) {
                c1=i-1;
            }
            s+='1';
        }
        string an="";
        REP(i,c1) an+='1';
        REP(i,n-c1) an+='0';
        ans(an);
        return;
    }
    string an="01";
    bool inv=0;
    for(int i=0;i<n-2;i++) {
        if(an.size()>=n) break;
        bool i1=qur(an+'0');
        if(i1) {
            an+='0';
            continue;
        }
        bool i2=qur(an+'1');
        if(i2) {
            an+='1';
            continue;
        }
        reverse(ALL(an));
        inv=1;
    }
    if(inv) reverse(ALL(an));
    ans(an);
}
signed main() {
    IOS(); 
    int T=1;
    cin>>T;
    while(T--) 
    solve();
    return 0;
}