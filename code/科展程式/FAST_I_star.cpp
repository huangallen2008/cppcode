#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,popcnt")
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
#define MD(x,M) (((x)%(M)+(M))%(M))
#define ld long double
#define pdd pair<ld,ld>
#ifdef LOCAL
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
const int mod=1e9+7;
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
ofstream Fstardata,maxaidata;
long double mn=100;
int nowa=0,nowb=0,nowc=0;
int tran(int n) {
    int k=sqrt((n<<1)-2);
    for(;;k++) if(k*(k+1)>=n<<1) return n+k+1;
    return n+((ld)sqrt((ld)(n<<1))+0.5)+1;
}
void solve(int l) {
    int rest=0,now;
    for(int i=1;;i++) {
        if(i*(i+1)>l*2) {
            rest=(i*(i+1)>>1)-l;
            now=i;
            break;
        }
    }
    while(1) {
        int lrest=rest;
        rest=tran(rest)-l;
        if(lrest<=rest) {
            if(lrest+l<<1==now*(now+1)) now--;
            break;
        }
        now++;
        if(rest<=0) rest+=now*(now+1)>>1;
        // op(now)ope(rest)
    }
    int maxai=l-1+(l-2)*(log((long double)(l-2))+(long double)1/(l*2-4)+0.577215664901532860606512090082402431042159335);
    // long double maxai=l-1;
    // REP1(i,l-1) maxai+=(ld)(l-1)/i;
    // cout<<l<<' '<<now<<" "<<maxai<<" "<<(now<=maxai?"YES":"NO")<<"\n";
    // op(l)op(now)ope(maxai)
    
    
    // cout<<l<<','<<now<<'\n';
    // cout<<l<<','<<maxai<<'\n';

    Fstardata<<l<<','<<now<<'\n';
    maxaidata<<l<<','<<maxai<<'\n';

            // if(now>maxai) {
            //     cout<<"find! l="<<l<<' '<<now<<' '<<maxai<<' ';
            //     cout<<fixed<<setprecision(15)<<(ld)((ld)maxai/now)<<endl;
            // }
    // entr
    if(maxai<=mn*now) {
        mn=(long double)maxai/now;
        nowa=now,nowb=maxai,nowc=l;
    }
}
signed main() {
    IOS();
    // int n;
    // cin>>n;

    // freopen("F_I_star_data.csv","a",stdout);
    // freopen("MAXai.csv","a",stdout);

    Fstardata.open("F_I_star_data.csv",ios::app);
    maxaidata.open("MAXai.csv",ios::app);
    for(int i=80000;i<100000;i++)solve(i);
    // cout<<fixed<<setprecision(15)<<mn<<'\n';
    // cout<<nowa<<' '<<nowb<<' '<<nowc<<'\n';
    return 0;
}