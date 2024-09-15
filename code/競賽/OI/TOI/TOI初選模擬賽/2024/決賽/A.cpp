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
const int maxv=4e4+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)

int n,m,k;
vector<int> id;
signed main() {
    IOS();
    cin>>n>>m>>k;
    n--;
    int mxs=0;
    id=vector<int>(n);
    REP(i,n) {
        id[i]=min(m-n+i+1,i*(i+1)/2+1);
        mxs+=id[i];
    }
    if(k<n*(n+1)/2||k>mxs) {
        cout<<"-1\n";
        return 0;
    }
    int adis=mxs-k;
    REP1(i,n-1) {
        int dis=id[i]-id[i-1]-1;
        if(adis<=0) break;
        if(adis>=dis) {
            adis-=dis;
            id[i]=id[i-1]+1;
        }
        else {
            id[i]-=adis;
            adis=0;
            break;
        }
    }
    if(adis>0) {
        cout<<"-1\n";
        return 0;
    }
    int it=0;
    pii nown={3,1};
    vector<bool> an(m+1);
    for(int v:id) an[v]=1;
//    int cnt=1;
//    REP1(i,m) {
//        if(an[i]) {
//            cout<<cnt++<<' '<<cnt<<'\n';
//        }
//        else {
//
//        }
//    }
    REP1(i,m) {
        if(it<id.size()&&id[it]==i) {
            it++;
            cout<<it<<' '<<it+1<<'\n';
        }
        else {
            cout<<nown.f<<' '<<nown.s<<'\n';
            if(nown.s>1) {
                nown.s--;
            }
            else {
                nown.f++;
                nown.s=nown.f-2;
            }
        }
    }
    return 0;
}
