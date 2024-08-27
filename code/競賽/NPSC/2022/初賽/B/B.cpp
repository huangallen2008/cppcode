#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n+1)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const ll inf=(1ll<<63)-1;
const int maxn=1e4+5;
const ll mod=1e9+7;
int n;
string s;
vector<int> an={1};
bool ok=0;
void d(int u) {
    int l=0,r=u-1,m;
    while(l<r) {
        m=(l+r)/2;
        cout<<2<<" ";
        cout<<u<<" "<<an[m]<<"\n";
        cout<<flush;
        cin>>s;
        if(s[0]=='G') {
            ok=1;
            return ;
        }
        if(s[0]=='T') {
            r=m;
        }
        else {
            l=m+1;
        }
    }
    an.insert(an.begin()+l,u);
}
signed main()
{
    IOS();
    cin>>n;
    for(int i=2;i<=n;i++) {
        d(i);
        if(ok) break;
    }
    if(!ok){
    cout<<n<<" ";
    REP(i,n) cout<<an[i]<<" ";
    cout<<"\n";
    cout<<flush;
    cin>>s;
    }
    return 0;
}
//52314
