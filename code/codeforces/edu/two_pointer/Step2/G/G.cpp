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
const int maxn=300+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct my_stk {
    vector<int> os,stk;
    void push(int x) {
        os.pb(x);
        if(stk.size()) {
            stk.pb(__gcd(stk.back(),x));
        }
        else {
            stk.pb(x);
        }
    }
    int pop() {
        int t=os.back();
        os.pop_back();
        stk.pop_back();
        return t;
    }
    int gcd() { 
        if(stk.size()) return stk.back();
        return -1;    
    }
    int size() { return stk.size(); }
};
struct my_que {
    my_stk s1,s2;
    void push(int x) {
        s1.push(x);
    }
    int pop() {
        if(s2.size()) {
            return s2.pop();
        }
        else {
            while(s1.size()>1) {
                s2.push(s1.pop());
            }
            return s1.pop();
        }
        return 0;
    }
    int gcd() { 
        if(s1.gcd()==-1) return s2.gcd();
        if(s2.gcd()==-1) return s1.gcd();
        return __gcd(s1.gcd(),s2.gcd());    
    }
    int size() { return s1.size()+s2.size(); }
}q;
signed main() {
    IOS();
    int n;
    cin>>n;
    vector<int> a(n);
    REP(i,n) cin>>a[i];
    int r=0,an=inf;
    REP(l,n) {
        while(r<n&&q.gcd()!=1) {
            q.push(a[r++]);
        }
        if(q.gcd()!=1) break;
        chmin(an,r-l); 
        q.pop();
    }
    if(an==inf) cout<<"-1\n";
    else cout<<an<<'\n';
    return 0;
}