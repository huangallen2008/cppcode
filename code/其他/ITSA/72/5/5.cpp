#include<bits/stdc++.h>
using namespace std;
string p,s,tt;
int a[1000000],b[1000000],c=0;
unordered_map<int,int> m;
stringstream ss1,ss2;
void f(int al,int ar,int bl,int br) {
    if(al==ar) {
        cout<<a[al]<<" ";
        return;
    }
    int t=m[a[al]];
    f(al+1,al+t-bl,bl,t-1);
    f(al+t-bl+1,ar,t+1,br);
    cout<<a[al]<<(al==0 && ar==c-1?"":" ");
}
main()
{
    getline(cin,p);
    ss1<<p;
    getline(cin,s);
    ss2<<s;
    while(ss1>>tt) a[c++]=stoi(tt);
    c=0;
    while(ss2>>tt) b[c++]=stoi(tt);
    for(int i=0;i<c;i++) m[b[i]]=i;
    f(0,c-1,0,c-1);
    cout<<"\n";
    return 0;
}
