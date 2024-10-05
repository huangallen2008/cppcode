#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define int long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
const int mod=1e9+7;
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
int n,m;
vector<bool> ok;
void yes(int u) {
    for(int i=u;i<u+m;i++) ok[i]=1;
}
signed main() {
    IOS();
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    int N=n-m+1,OK=(1<<m)-1;
    ok=vector<bool>(n);
    vector<int> a(N);
    REP(i,N) {
        REP(j,m) if(s[i+j]==t[j]) a[i]|=(1<<j);
    }
//    oparr(a)
    vector<int> rm(N);
    queue<int> q;
    REP(i,N) {
        if(a[i]==OK) {
            q.push(i);
            rm[i]=1;
            yes(i);
        }
    }
    while(q.size()) {
        int u=q.front();
        q.pop();
        int t=OK;
        for(int i=u+1;i<u+m&&i<N;i++) {
            t>>=1;
            if(rm[i]) continue;
            a[i]|=t;
            if(a[i]==OK) {
                rm[i]=1;
                yes(i);
                q.push(i);
            }
        }
        t=OK;
        for(int i=u-1;i>u-m&&i>=0;i--) {
            t&=~(1<<(u-1-i));
            if(rm[i]) continue;
            a[i]|=t;
            if(a[i]==OK) {
                rm[i]=1;
                yes(i);
                q.push(i);
            }
        }
    }
    int cnt=0;
    REP(i,n) cnt+=ok[i];
    if(cnt==n) cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}
