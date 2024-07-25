#include<stdio.h>
#include<vector>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n+1)
using namespace std;
signed main()
{
    int T;
    scanf("%d",&T);
    while(T--) {
        int n,m;
        scanf("%d %d",&n,&m);
        vector<int> a(m);
        bool ok=1;
        REP(j,m) scanf("%d",&a[j]);
        int l,x;
        REP1(i,n-1) {
            scanf("%d",&l);
            REP1(j,m-1) {
                scanf("%d",&x);
                if(x!=a[j-1]) ok=0;
                a[j-1]=l;
                l=x;
            }
        }
        if(ok) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
