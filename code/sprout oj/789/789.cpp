#include<bits/stdc++.h>
using namespace std;
int n,a[100005]={};
void f(int r,int p) {
    if(r+p>n) { cout<<p<<" "; return; }
    f(r*2,p); f(r*2,r+p);
}
main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n;
    f(1,1); cout<<"\n";
    return 0;
}
