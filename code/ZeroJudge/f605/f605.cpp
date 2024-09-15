#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,d,c=0,an=0;
    cin>>n>>d;
    for(int i=0;i<n;i++) {
        int s=101,b=-1,a,al=0;
        for(int j=0;j<3;j++) {
            cin>>a;
            al+=a;
            if(a<s)
                s=a;
            if(a>b)
                b=a;
        }
        if(b-s>=d) {
            c++;
            an+=al/3;
        }
    }
    cout<<c<<" "<<an;
	return 0;
}
