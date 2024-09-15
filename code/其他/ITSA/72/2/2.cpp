#include<bits/stdc++.h>
using namespace std;
string p;
int a[1000000],c=0;
unordered_map<int,int> m;
bool b=true;
main()
{
    getline(cin,p);
    ss1<<p;
    while(ss1>>tt) a[c++]=stoi(tt);
    for(int i=0;i<c;i++) {
        m[a[i]]++;
        if(m[a[i]]>(c+1)/2)) {
            cout<<a[i]<<"\n";
            b=false;
        }
    }
    if(b) cout<<"n/a\n";
    return 0;
}
