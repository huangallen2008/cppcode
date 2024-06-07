#include <bits/stdc++.h>
using namespace std;
int a[4][4],p[4]={};
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    for(int i=0;i<4;i++) { for(int j=0;j<4;j++) { cin>>a[i][j]; p[i]+=a[i][j]; } }
    cout<<p[0]<<":"<<p[1]<<"\n"<<p[2]<<":"<<p[3]<<"\n";
    if(p[0]>p[1] && p[2]>p[3]) cout<<"Win";
    else if(p[0]<p[1] && p[2]<p[3]) cout<<"Lose";
    else cout<<"Tie";
    return 0;
}
