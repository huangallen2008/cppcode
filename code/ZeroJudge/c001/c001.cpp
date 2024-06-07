#include<bits/stdc++.h>
using namespace std;
string a,b;
int h[1005][1005]={};
main()
{
    while(cin>>a>>b) {
        memset(h,0,sizeof(h));
        for(int i=1;i<=a.size();i++) {
            for(int j=1;j<=b.size();j++) {
                if(a[i-1]==b[j-1]) h[i][j]=h[i-1][j-1]+1;
                else   h[i][j]=max(h[i][j-1],h[i-1][j]);
            }
        }
        cout<<h[a.size()][b.size()]<<"\n";
    }
    return 0;
}
