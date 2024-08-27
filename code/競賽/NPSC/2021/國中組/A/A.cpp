#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,an1=0,an2=0,c1=0,c2=0;
    cin>>n;
    string a[n]={};
    for(int i=0;i<n;i++) {
        cin>>a[i];
        for(int j=0;j<n;j++) {
            if(a[i][j]=='O')
                c1++;
            else
                c2++;
        }
    }
    if(c1-c2!=0 && c1-c2!=1)
        cout<<"Impossible\n";
    else {
        char l;
        bool b;
        for(int i=0;i<n;i++) {
            b=true;
            l=a[i][0];
            for(int j=1;j<n;j++) {
                if(a[i][j]!=l) {
                    b=false;
                    break;
                }
            }
            if(b) {
                if(l=='O')
                    an1++;
                else
                    an2++;
            }
        }
        for(int i=0;i<n;i++) {
            b=true;
            l=a[0][i];
            for(int j=1;j<n;j++) {
                if(a[j][i]!=l) {
                    b=false;
                    break;
                }
            }
            if(b) {
                if(l=='O')
                    an1++;
                else
                    an2++;
            }
        }
        b=true;
        l=a[0][0];
        for(int i=1;i<n;i++) {
            if(a[i][i]!=l) {
                b=false;
                break;
            }
        }
        if(b) {
            if(l=='O')
                an1++;
            else
                an2++;
        }
        b=true;
        l=a[0][n-1];
        for(int i=1;i<n;i++) {
            if(a[i][n-i-1]!=l) {
                b=false;
                break;
            }
        }
        if(b) {
            if(l=='O')
                an1++;
            else
                an2++;
        }
        cout<<an1<<" "<<an2<<"\n";
    }
    return 0;
}
