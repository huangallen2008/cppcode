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
#define ld long double
const int mod=1e9+7;
const int maxn=1e6+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
signed main() {
    IOS();
    int n;
    cin>>n;
//    while(cin>>n){
    vector<int> v(n);
    REP(i,n) cin>>v[i];
    sort(ALL(v));
    int mx=0;
    vector<int> an(n);
    do{
        int r=inf;
        REP(i,n-1) r=min(r,abs(v[i]-v[i+1]));
//        ope(r)
        if(r>=mx) {
                mx=r;
//            an=v;
//            oparr(v)
        }
    }while(next_permutation(ALL(v)));
    do{
        int r=inf;
        REP(i,n-1) r=min(r,abs(v[i]-v[i+1]));
//        ope(r)
        if(r==mx) {
            oparr(v)
        }
    }while(next_permutation(ALL(v)));
    if(n&1){
        int x=v[n/2];
        v.erase(v.begin()+n/2);
        n--;
        vector<int> an1(n),an2(n);
        int cnt=0;
        for(int i=1;i<n;i+=2) an1[i]=v[cnt++];
        for(int i=0;i<n;i+=2) an1[i]=v[cnt++];
        cnt=0;
        for(int i=0;i<n;i+=2) an2[i]=v[cnt++];
        for(int i=1;i<n;i+=2) an2[i]=v[cnt++];
        vector<int>an3=an1;reverse(ALL(an3));
        vector<int>an4=an2;reverse(ALL(an4));
        int a1=abs(an1[0]-x),a2=abs(an2[0]-x),a3=abs(an3[0]-x),a4=abs(an4[0]-x);
        REP(i,n-1) a1=min(a1,abs(an1[i]-an1[i+1]));
        REP(i,n-1) a2=min(a2,abs(an2[i]-an2[i+1]));
        REP(i,n-1) a3=min(a3,abs(an3[i]-an3[i+1]));
        REP(i,n-1) a4=min(a4,abs(an4[i]-an4[i+1]));
//        op(a1)op(a2)op(a3)ope(a4)
        int na=a1;
        an=an1;
        if(a2>na) {
            na=a2;
            an=an2;
        }
        if(a3>na) {
            na=a3;
            an=an3;
        }
        if(a4>na) {
            na=a4;
            an=an4;
        }
//        oparr(an1)oparr(an2)
        cout<<x<<" ";
        REP(i,n) cout<<an[i]<<" ";
    }
    else {
        int cnt=0;
        for(int i=1;i<n;i+=2) an[i]=v[cnt++];
        for(int i=0;i<n;i+=2) an[i]=v[cnt++];
        REP(i,n) cout<<an[i]<<" ";
    }
    cout<<'\n';

//    entr}
    return 0;
}
