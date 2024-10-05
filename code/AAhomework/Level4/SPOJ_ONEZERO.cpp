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
const int maxv=1e6;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
void solve() {
    int n;
    cin>>n;
    vector<int> dis(n,inf),last(n),use(n);
    queue<int> q;
    q.push(1);
    dis[1]=0;
    while(q.size()) {
        int u=q.front();
        q.pop();
//        ope(u)
        int v1=(u*10)%n;
        if(dis[v1]>dis[u]+1) {
            dis[v1]=dis[u]+1;
            last[v1]=u;
            use[v1]=0;
            q.push(v1);
        }
        int v2=(u*10+1)%n;
        if(dis[v2]>dis[u]+1) {
            dis[v2]=dis[u]+1;
            last[v2]=u;
            use[v2]=1;
            q.push(v2);
        }
    }
//    oparr(use)oparr(last)
    string s;
    int nu=0;
    while(nu!=1) {
        s+='0'+use[nu];
        nu=last[nu];
    }
    s+='1';
    reverse(ALL(s));
    cout<<s<<'\n';
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
