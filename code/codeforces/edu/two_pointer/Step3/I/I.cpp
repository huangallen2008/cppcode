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
#define oparr(x) cout<<(#x)<<":";for(auto &allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=7e5+5;
const int maxs=1000+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct my_stk {
    vector<int> stk,dp;
    my_stk() {
        dp=vector<int>(maxs);
        dp[0]=1;
    }
    void push(int x) {
        stk.pb(x);
        for(int i=maxs-1;i>=x;i--) dp[i]+=dp[i-x];
    }
    int pop() {
        int x=stk.back();
        for(int i=x;i<maxs;i++) dp[i]-=dp[i-x];
        stk.pop_back();
        return x;
    }
    int size() { return stk.size(); }
    bool ok(int s) { return dp[s]; }
};
struct my_que {
    my_stk s1,s2;
    void push(int x) {
        s1.push(x);
        REP(i,101) if(s1.ok(i)) cout<<i<<' ';entr
        REP(i,101) if(s2.ok(i)) cout<<i<<' ';entr
    }
    int pop() {
        if(s2.size()) return s2.pop();
        else {
            while(s1.size()>1) {
                s2.push(s1.pop());
            }
            return s1.pop();
        }
    }
    int size() { return s1.size()+s2.size(); }
    bool ok(int s) {
        REP(i,s+1) {
            if(s1.ok(i)&&s2.ok(s-i)) return 1;
        }
        return 0;
    }
} q;
signed main() {
    IOS();
    int n,s;
    cin>>n>>s;
    vector<int> a(n);
    REP(i,n) cin>>a[i];
    int r=0,an=inf;
    REP(l,n) {
        while(r<n&&!q.ok(s)) {
            q.push(a[r++]);
        }
        if(!q.ok(s)) break;
        q.pop();
        chmin(an,r-l);
    }
    cout<<an<<'\n';
    return 0;
}