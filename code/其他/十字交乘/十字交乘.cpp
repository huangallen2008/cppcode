#include<bits/stdc++.h>
using namespace std;
string t(int n) {
    if(n!=1) cout<<"n";
    return "";
}
main()
{
    int a1,a2,a3;
    while(cin>>a1>>a2>>a3) {
        if(a1==0) {
            cout<<"!!!\n";
            continue;
        }
        if(a1<0) {
            a1*=-1;
            a2*=-1;
            a3*=-1;
        }
        int a,b;
        bool h=true;
        for(int j=1;j<=(int)sqrt(a1)+1;j++) {
            if(a1%j==0) {
                a=j; b=a1/j;
                for(int i=1;i<=abs(a3);i++) {
                    if(abs(a3)%i==0) {
                        int x=i,y=abs(a3)/i;
                        if(a3<0) {
                            if(x*a-y*b==a2) {
                                cout<<"("<<t(a)<<"x-"<<y<<")("<<t(b)<<"x+"<<x<<")=0\n";
                                h=false;
                            }
                            else if(x*a-y*b==-a2) {
                                cout<<"("<<t(a)<<"x+"<<y<<")("<<t(b)<<"x-"<<x<<")=0\n";
                                h=false;
                            }
                            else if(x*b-y*a==a2) {
                                cout<<"("<<t(a)<<"x-"<<x<<")("<<t(b)<<"x+"<<y<<")=0\n";
                                h=false;
                            }
                            else if(x*b-y*a==-a2) {
                                cout<<"("<<t(a)<<"x+"<<x<<")("<<t(b)<<"x-"<<y<<")=0\n";
                                h=false;
                            }
                        }
                        else {
                            if(x*a+y*b==a2) {
                                cout<<"("<<t(a)<<"x+"<<y<<")("<<t(b)<<"x+"<<x<<")=0\n";
                                h=false;
                            }
                            else if(x*a+y*b==-a2) {
                                cout<<"("<<t(a)<<"x-"<<y<<")("<<t(b)<<"x-"<<x<<")=0\n";
                                h=false;
                            }
                            else if(x*b+y*a==a2) {
                                cout<<"("<<t(a)<<"x+"<<x<<")("<<t(b)<<"x+"<<y<<")=0\n";
                                h=false;
                            }
                            else if(x*b+y*a==-a2) {
                                cout<<"("<<t(a)<<"x-"<<x<<")("<<t(b)<<"x-"<<y<<")=0\n";
                                h=false;
                            }
                        }
                    }
                }
            }
        }
        if(h)
            cout<<"no\n";
    }
    return 0;
}
