#include<bits/stdc++.h>
using namespace std;
int T,n,a[101][101],c=0,an=0;
char t;
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>T;
    while(T--) {
        an=0;
        cin>>n;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cin>>t;
                a[i][j]=t-'0';
            }
        }
        for(int i=0;i<n/2;i++) {
            for(int j=i;j<n-1-i;j++) {
                c=0;
                if(a[i][j]==0) c++;
                if(a[j][n-1-i]==0) c++;
                if(a[n-1-i][n-1-j]==0) c++;
                if(a[n-1-j][i]==0) c++;
                an+=min(c,4-c);
            }
        }
        cout<<an<<"\n";
    }
    return 0;
}
