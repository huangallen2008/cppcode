#include<bits/stdc++.h>
using namespace std;
#define int long long
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
#define START clock_t start,end;start=clock();ifstream cin;ofstream cout;
#define END end=clock();cout.close();std::cout<<fixed<<setprecision(3)<<"time:"<<double(end-start)/CLOCKS_PER_SEC<<"s\n";
//#define cin in
const int inf=(1ll<<62);
const int maxn=2e5+5;
const int mod=1e9+7;
bool so(int a,int b) {
    return a>b;
}
signed main() {
    IOS();
//    START;
//    cout.open("11_out.txt");
//    cin.open("11_in.txt");
//    cin.open("../../other/test/out.txt");
    int n,m;
    cin>>n>>m;
    vector<int> r(n),c(m);
    int sum=0;
    REP(i,n) {
        REP(j,m) {
            int x;
            cin>>x;
            sum+=x;
            if(i==0) sum+=x;
            if(i==n-1) sum+=x;
            if(j==0) sum+=x;
            if(j==m-1) sum+=x;
            if(i>0) r[i-1]+=x;
            if(j>0) c[j-1]+=x;
            if(i<n-1) r[i]+=x;
            if(j<m-1) c[j]+=x;
        }
    }
    sort(ALL(r),so);
    sort(ALL(c),so);
    vector<int> pr(n),pc(m);
    REP1(i,n-1) pr[i]=pr[i-1]+r[i-1];
    REP1(i,m-1) pc[i]=pc[i-1]+c[i-1];
    vector<int> an(n*m+1,-1);
    REP1(i,n) {
        REP1(j,m) {
            an[i*j]=max(an[i*j],pr[i-1]+pc[j-1]+sum);
        }
    }
    REP1(i,n*m) cout<<an[i]<<" ";
    cout<<"\n";
//    END;
    return 0;
}
