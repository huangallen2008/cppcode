#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<string> v,a;
void d(int l,int r) {
    if(isdigit(v[l][0])) a.push_back(v[l]);
    else if(v[l]=="not") {
        a.push_back("not");
        a.push_back("(");
        d(l+2,r-1);
        a.push_back(")");
    }
    else {
        int t=0;
        for(int i=l;i<=r;i++) {
            if(v[i]=="(") t++;
            if(v[i]==")") t--;
            if(t==0) {
                if(v[i]=="or") {
                    a.push_back("(");
                    d(l+1,i-2);
                    a.push_back(")");
                    a.push_back("or");
                    a.push_back("(");
                    d(i+2,r-1);
                    a.push_back(")");
                }
                if(v[i]=="and") {
                    a.push_back("not");
                    a.push_back("(");
                    a.push_back("(");
                    a.push_back("not");
                    a.push_back("(");
                    d(l+1,i-2);
                    a.push_back(")");
                    a.push_back(")");
                    a.push_back("or");
                    a.push_back("(");
                    a.push_back("not");
                    a.push_back("(");
                    d(i+2,r-1);
                    a.push_back(")");
                    a.push_back(")");
                    a.push_back(")");
                }
            }
        }
    }
}
main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++) {
        string t;
        cin>>t;
        v.push_back(t);
    }
    d(0,m-1);
    cout<<a.size()<<"\n";
    for(int i=0;i<a.size();i++) {
        cout<<a[i]<<" ";
    }cout<<"\n\n";
    /*bool b=true; //´ú¸Õ¬O§_¥¿½T
    for(int i=0;i<a.size();i++) {
        string s;
        cin>>s;
        if(s!=a[i]) {
            cout<<"\n\nNo!!!\n";
            b=false;
            break;
        }
    }
    if(b) cout<<"\n\nYes!!!\n";*/
    return 0;
}
