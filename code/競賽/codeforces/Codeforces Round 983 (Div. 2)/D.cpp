#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("Ofast,unroll-loops,fast-math")
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
#define ALL1(x) (x).begin()+1,(x).end()
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
const int maxn=1e5+5;
const int maxn2=2e5+5;
const int maxb=19;
const int inf=(1ll<<62); 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n;
int qur(int a,int b) {
    cout<<"? "<<a<<" "<<b<<"\n";
    cout.flush();
    int x;
    cin>>x;
    return x;
}
int ans(Vi an) {
    cout<<"! ";
    REP1(i,n-1) cout<<an[i]<<' ';
    cout<<'\n';
    cout.flush();
}
void solve() {
    cin>>n;
    Vi p0={1};
    Vi p(n);
    p[1]=0;
    for(int i=2;i<n;i++) {
        if(qur(1,i)) p0.pb(i),p[i]=0;
        else break;
    }
    int fir=p0.back()+2;
    p[fir-1]=1;
    set<int> st;
    for(int x:p0) st.insert(x);
    for(int i=fir;i<n;i++) {
        for(int pp:st) {
            st.erase(pp);
            if(!qur(pp,i)) {
                p[i]=pp;
                st.insert(i);
               break;
            }
        }
    }
    ans(p);
}
signed main() {
    IOS(); 
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}