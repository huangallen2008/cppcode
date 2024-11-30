#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
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
const int maxn=5e5+5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS(); 
    int n;
    cin>>n;
    Vi a(n);
    REP(i,n) cin>>a[i];
    if(n==2) {
        if(a[0]>=a[1]) cout<<a[0]*2-a[1]<<'\n';
        else cout<<"-1\n";
        return 0;
    }
    auto check=[&](int m) {
        Vi v=a;
        int c2=0;
            REP(i,n-2) {
                if(v[i]+c2*2>m) {
                    int tt=(m-v[i])/2;
                    v[i]+=tt*2;
                    c2-=tt;
                }else {
                    v[i]+=c2*2;
                    c2=0;
                }
                if(v[i]<m) {
                    c2+=m-v[i];
                }
            }
            if((m-v[n-2])&1) v[n-2]++,c2++;
            bool ok1=c2<=(m-v[n-2]+m-v[n-1]>>1);
            int c22=0;
            Vi v2=a;
            REP(i,n-1) c22+=m-v2[i];
            bool ok2=c22>=(m-v2[n-1]>>1);//ok2=1; 
            return ok1&&ok2;
    };
    int sum=0,mx=*max_element(ALL(a));
    REP(i,n) sum+=a[i];
    if(n%3==0) {
        int rr=a[n-1]%2;
        int lb=mx/2,rb=1e15,mb;
        if(rr<mx%2) lb++;
        while(lb<rb) {
            mb=lb+rb>>1;
            // Vi v=a;
            // int m=mb*2+a[n-1];
            // int c2=0;
            // REP(i,n-2) {
            //     if(v[i]+c2*2>m) {
            //         int tt=(m-v[i])/2;
            //         v[i]+=tt*2;
            //         c2-=tt;
            //     }else {
            //         v[i]+=c2*2;
            //         c2=0;
            //     }
            //     if(v[i]<m) {
            //         c2+=m-v[i];
            //     }
            // }
            // if((m-v[n-2])&1) v[n-2]++,c2++;
            // if(c2>(m-v[n-2]+m-v[n-1]>>1)) lb=mb+1;
            // else rb=mb;
            if(check(mb*2+rr)) rb=mb;
            else lb=mb+1;
        }
        if(!check(lb*2+rr)){
            cout<<"-1\n";
            return 0;
        }
        ope(lb)
        cout<<lb*2+a[n-1]<<'\n';
    }else {
        //an*n%3==sum%3
        int rr=0;
        REP(i,6) {
            if(i*n%3==sum%3&&i%2==a[n-1]%2) {
                rr=i;
                break;
            }
        }

        int lb=mx/6,rb=1e15,mb;
        if(rr<mx%6)lb++;
        while(lb<rb) {
            mb=lb+rb>>1;
            // Vi v=a;
            // int m=lb*6+rr;
            // int c2=0;
            // REP(i,n-2) {
            //     if(v[i]+c2*2>m) {
            //         int tt=(m-v[i])/2;
            //         v[i]+=tt*2;
            //         c2-=tt;
            //     }else {
            //         v[i]+=c2*2;
            //         c2=0;
            //     }
            //     if(v[i]<m) {
            //         c2+=m-v[i];
            //     }
            // }
            // if((m-v[n-2])&1) v[n-2]++,c2++;
            // if(c2>(m-v[n-2]+m-v[n-1]>>1)) lb=mb+1;
            // else rb=mb;
            if(check(lb*6+rr)) rb=mb;
            else lb=mb+1;
        }
        if(!check(lb*6+rr)) {
            cout<<"-1\n";
            return 0;
        }
        // op(lb)ope(rr)
        cout<<lb*6+rr<<'\n';
    }
    return 0;
}