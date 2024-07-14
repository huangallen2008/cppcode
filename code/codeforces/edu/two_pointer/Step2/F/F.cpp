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
const int maxn=1e4+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct my_stk {
    vector<int> stk,mx,mn;
    void push(int x) {
        stk.pb(x);
        mx.pb(mx.size()?max(mx.back(),x):x);
        mn.pb(mn.size()?min(mn.back(),x):x);
    }
    int pop() {
        int x=stk.back();
        stk.pop_back();
        mx.pop_back();
        mn.pop_back();
        return x;
    }
    int size() { return stk.size(); }
    int mxe() { return mx.size()?mx.back():0; }
    int mne() { return mn.size()?mn.back():inf; }
};
struct my_que {
    my_stk s1,s2;
    void push(int x) {
        s1.push(x);
    }
    int pop() {
        if(s2.size()) return s2.pop();
        else {
            while(s1.size()>1) s2.push(s1.pop());
            return s1.pop();
        }
    }
    int size() { return s1.size()+s2.size(); }
    int mx() { return max(s1.mxe(),s2.mxe()); }
    int mn() { return min(s1.mne(),s2.mne()); }
    int dif() { return mx()-mn(); }  
}q;
signed main() {
    IOS();
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    REP(i,n) cin>>a[i];
    int r=0,an=0;
    REP(l,n) {
        while(r<n&&q.dif()<=k) q.push(a[r++]);
        if(q.dif()<=k) an++;
        an+=r-l-1;
        q.pop();
    }
    cout<<an<<'\n';
    return 0;
}