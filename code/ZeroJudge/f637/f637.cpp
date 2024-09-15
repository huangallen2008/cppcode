#include<bits/stdc++.h>
using namespace std;
string s;
int n;
array<int,2> h(int u,int m) {
    int a=0,c=4,i=u+1;
    while(c) {
        if(s[i]=='0')
            i++;
        else if(s[i]=='1') {
            a+=m*m;
            i++;
        }
        else {
            array<int,2> tt=h(i,m/2);
            a+=tt[0];
            i=tt[1];
        }
        c--;
    }
    array<int,2> an;
    an[0]=a; an[1]=i;
    return an;

}
main()
{
    cin>>s>>n;
    if(s[0]=='0')
        cout<<0;
    else if(s[0]=='1')
        cout<<n*n;
    else
        cout<<h(0,n/2)[0];
    return 0;
}
