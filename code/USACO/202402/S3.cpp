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
#ifdef LOCAL
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=1e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
void solve() {
    int n,P;
    cin>>n>>P;
    vector<bool> s1(n),s2(n);
    REP(i,n) {
        char c;
        cin>>c;
        s1[i]=(c=='2');
    }
    REP(i,n) {
        char c;
        cin>>c;
        s2[i]=(c=='2');
    }
    vector<int> a={s1[0]},b={s2[0]};
    REP(i,n-1) if(s1[i]^s1[i+1]) a.pb(s1[i+1]);
    REP(i,n-1) if(s2[i]^s2[i+1]) b.pb(s2[i+1]);
//    oparr(a)oparr(b)
    vector<pii> an;
    int v1=1,v2=3;
    vector<int> cnt(4);
    if(a.back()^b.back()) swap(v1,v2);
    REP(i0,b.size()) {
        if(i0==b.size()-1) {
            v1=3,v2=2;
            if(b[0]==a.back()) {
                v1=3,v2=2;
                break;
            }
            if((b.size()+1)/2==1)  {
                v1=3,v2=2;
                break;
            }
            break;
        }
        int i=b.size()-i0-1;
        if(i0&1) {
            an.pb({2,v2});
            cnt[v2]++;
        }
        else {
            an.pb({2,v1});
            cnt[v1]++;
        }
    }
    if(cnt[3]>0) an.pb({3,2});
    cnt[3]=0;
    REP(i0,a.size()) {
        if(i0==a.size()-1&&a[0]==(v1==2)^a.back()) continue;
        int i=a.size()-i0-1;
        if(i0&1) {
            an.pb({1,v2});
            cnt[v2]++;
        }
        else {
            an.pb({1,v1});
            cnt[v1]++;
        }
    }
    if(cnt[3]>0)an.pb({3,1});
    cout<<an.size()<<'\n';
    if(P>1) for(auto &[x,y]:an) cout<<x<<' '<<y<<'\n';
//    entr
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
