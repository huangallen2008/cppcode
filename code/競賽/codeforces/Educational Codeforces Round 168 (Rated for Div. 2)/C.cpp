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
#ifdef LOCAL_
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
void solve() {
    string s;
    int n;
    cin>>n>>s;
    int v=0,cnt=0;
    REP(i,n) {
        if(s[i]=='(') v++;
        if(s[i]==')') v--;
        if(s[i]=='_') cnt++;
    }
    //l+r=cnt,l-r=-v
    op(cnt)ope(v)
    int l=cnt-v>>1,r=cnt+v>>1;
    int now=0;
    priority_queue<int> pq;
    REP(i,n) {
        op(i)op(now)op(l)ope(r)ope(s)
        if(s[i]=='_') {
            if(now>0&&r>0) {
                now--,r--;
                s[i]=')';
                pq.push(i);
            }
            else {
                now++;
                l--;
                s[i]='(';
            }
        }
        else if(s[i]=='(') now++;
        else if(s[i]==')') {
            now--;
            if(now<0) {
                auto t=pq.top();
                pq.pop();
                s[t]='(';
                l--,r++,now+=2;
            }
        }
    }
    ope(s)
    int an=0;
    REP(i,n) {
        if(s[i]=='(') an-=i;
        else an+=i;
    }
    cout<<an<<'\n';
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) 
    solve();
    return 0;
}