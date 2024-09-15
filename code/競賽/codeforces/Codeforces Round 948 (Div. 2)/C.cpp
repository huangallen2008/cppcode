//🔥🐥🔥🐥😭😭😭 怎麼會...?
#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,popcnt")
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
#define oparr(x) cout<<(#x)<<":";REP(allen,(x).size()) cout<<x[allen]<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=998244353;
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    REP(i,n) cin>>a[i];
    sort(ALL(a));
    oparr(a)
    bool ook=0;
    int an=0;
    RREP(i,n) {
        bool ok=1;
        REP(j,i) {
            if(a[i]%a[j]!=0) ok=0;
        }
        if(!ok) {
            if(i==n-1) {
                cout<<n<<'\n';
                return ;
            }
            unordered_map<int,int> fac,fcnt,aifac;
            {
            int t=a[i+1];
            for(int f=2;f*f<=a[i+1];f++) {
                int cnt=0;
                while(t%f==0) {
                    cnt++;
                    t/=f;
                }
                if(cnt==0) continue;
                fac[f]=cnt;
                op(f)ope(cnt)
            }
                if(t>0) fac[t]=1;ope(t)
            }
            {
                int t=a[i];
                for(int f=2;f*f<=a[i];f++) {
                    int cnt=0;
                    while(t%f==0) {
                        cnt++;
                        t/=f;
                    }
                    if(cnt==0) continue;
                    aifac[f]=cnt;
                }
                if(t>0) aifac[t]=1;
            }
            REP(j,i+1) {
                int t=a[j];
                for(int f=2;f*f<=a[j];f++) {
                    int cnt=0;
                    while(t%f==0) {
                        cnt++;
                        t/=f;
                    }
                    if(fac[f]==cnt) fcnt[f]++;
                }
                if(t>0&&fac[t]==1) fcnt[t]++;
            }
            op("---------------------")
            for(auto [fff,cnt]:fac) {
                op(fff)op(cnt)ope(fcnt[fff])
                if(fcnt[fff]==0&&cnt) {
                    chmax(an,i+1);
                    if(i+1==6) {
                        op("!!!")ope(an)
                    }
                }
            }
            for(auto [fff,cnt]:fcnt) {
                // op(fff)ope(cnt)
                if(aifac[fff]==fac[fff]) continue;
                chmax(an,i+1-cnt);
            }
            ope(an)
        }
    }
            cout<<an<<'\n';

}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) {
        solve();
        ope("-------------------")
    }
    return 0;
}
/*
1
7
2 3 4 6 12 100003 1200036
9
2 42 7 3 6 7 7 1 6

*/