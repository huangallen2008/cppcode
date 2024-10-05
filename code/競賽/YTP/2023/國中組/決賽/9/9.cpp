#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,popcnt")
#define ll long long
// #define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,(n)+1)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int inf=(1ll<<62);
const int maxn=1e5+5;
const int mod=1e9+9;
signed main()
{
    IOS();
    int n;
    cin>>n;
    vector<bitset<5000>> g(n);
    REP(i,n) {
        REP(j,n) {
            char c;
            cin>>c;
            if(c=='.') g[i][j]=1;
        }
    }
    int an=0;
    REP(l,n) {
        bitset<5000> x=g[l];
        for(int r=l;r<n;r++) {
            if(r>l) x&=g[r];
            int p=0;
            int a=0;
            REP(i,n) {
                if(x[i]==1) p++;
                else p=0;
//                cout<<a<<" ";
                a+=p;
            }
//            cout<<a<<" ";
            an+=a;
        }
//        cout<<"\n";
    }
    cout<<an<<"\n";
    return 0;
}
