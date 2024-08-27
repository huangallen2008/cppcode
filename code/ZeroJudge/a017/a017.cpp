#include<bits/stdc++.h>
using namespace std;
string s,a[50];
void d(int &an,int &la,string c,int t) {
    if(c=="+") {
        an+=la;
        la=t;
    }
    else if(c=="-") {
        an+=la;
        la=-t;
    }
    else if(c=="*") la*=t;
    else if(c=="/") la/=t;
    else la%=t;
}
int ccl(int l,int r) {
    int an=0,la=0;
    string c="+";
    for(int i=l;i<=r;i++) {
        if(isdigit(a[i][0])) {
            int t=stoi(a[i]);
            d(an,la,c,t);
        }
        if(a[i]=="(") {
            int r=1,tt=i+1;
            while(r>0) {
                i++;
                if(a[i]=="(") r++;
                if(a[i]==")") r--;
            }
            int t=ccl(tt,i-1);
            d(an,la,c,t);
        }
        else c=a[i];
    }
    return an+la;
}
main()
{
    while(getline(cin,s)) {
        stringstream ss(s);
        int n=-1;
        while(ss>>a[++n]){}
        cout<<ccl(0,n-1)<<"\n";
    }
    return 0;
}
