#include<bits/stdc++.h>
using namespace std;
#define int long long
using Matrix = vector<vector<int>>;
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
const int inf=(1ll<<63)-1;
const int maxn=1e5+5;
const int mod=1e9+7;
Matrix operator*(const Matrix &a,const Matrix &b) {
    Matrix c(SZ(a),vector<int>(SZ(b[0])));
    REP(i,a.size())
        REP(j,b[0].size())
            REP(k,a[0].size()) c[i][j]=(c[i][j]+a[i][k]*b[k][j])%mod;
    return c;
}
Matrix pow(Matrix a,int n) {//{a,b},{1,0}  {1,},{,1}
    Matrix ret={{1,0},{0,1}};
    while(n>0) {
        if(n&1) ret=ret*a;
        a=a*a;
        n>>=1;
    }
    return ret;
}
int x1,x2,a,b,n;
signed main()
{
    IOS();
    cin>>x1>>x2>>a>>b>>n;
    Matrix m={{x2},{x1}};
    Matrix an=pow({{b,a},{1,0}},n-1)*m;
    cout<<an[1][0]<<"\n";
    return 0;
}
