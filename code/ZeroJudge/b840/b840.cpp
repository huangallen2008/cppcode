#include<bits/stdc++.h>
using namespace std;
int n,a[25][25]={},m=0;
main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin>>a[i][j];
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    }
    for(int y=1;y<=n;y++)
        for(int z=1;z<=n;z++)
            for(int w=0;w<y;w++)
                for(int x=0;x<z;x++)
                    m=max(m,a[y][z]-a[w][z]-a[y][x]+a[w][x]);
    cout<<m;
	return 0;
}
